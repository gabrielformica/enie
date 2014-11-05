/**
  * Copyright 2014
  *
  * @file
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Caso class definition
  */


#ifndef CASO_HH
#define CASO_HH

#include <vector>
#include <string>
#include "node.hh"
#include "instruc.hh"
#include "instlist.hh"
#include "lambda_opt.hh"
#include "../interm_code/interm_code_helper.hh"
#include "../interm_code/quad.hh"


class Caso: public Instruc {
    private:
        ExpSimple *var;
        std::vector<LambdaOpt *> *optlist;
        LambdaOpt *otherwise;

    public:
        typedef Instruc super;

        Caso(ExpSimple *var, std::vector<LambdaOpt *> *optl, LambdaOpt *ow) :
            super(NULL) {
            this->var = var;
            this->optlist = optl;
            this->otherwise = ow;
            this->setType();
        }

        void setType() {
            this->type = this->var->getType(); //setting type

            int i;
            for (i = 0; i < this->optlist->size(); i++) {
                if ((*this->optlist)[i]->getType()->is("error"))
                    this->type = (*this->optlist)[i]->getType();
            }

            if (this->otherwise->getType()->is("error"))
                this->type = this->otherwise->getType();
        }

        std::string toString() {
            std::string str = "";
            str = "Caso:\n";
            str = str + "Variable: " + this->var->getElem() + "\n";
            str = str + "Conjunto de opciones: \n";
            for (int i = 0; i < this->optlist->size(); i++) {
                    str = str + (*this->optlist)[i]->toString() + "\n";
            }

            str = str + "Caso por defecto: (?) " + this->otherwise->toString();

            return str;
        }

        Quad *genCode() {
            // Labels for test and exit
            std::string test_label = get_next_label();
            std::string exit_label = get_next_label();
            ArgumentConst *test_arg = new ArgumentConst(test_label, NULL);
            ArgumentConst *exit_arg = new ArgumentConst(exit_label, NULL);

            // Comment quad
            Quad *case_quad = new Quad(this->line, "Caso");
            Quad *last_comment = new Quad(this->line, "Cierre-Caso");

            // Quad for the case variable
            Quad *var_quad = this->var->genCode();
            Argument *var_arg = var_quad->getResult();
            case_quad->appendToFinal(var_quad);


            // Unconditional jump to test section
            Quad *goto_test = new Quad("goto", NULL, NULL, test_arg);
            case_quad->appendToFinal(goto_test);

            Quad *tests = new Quad(0, "");

            // Generation for list of case options
            std::vector<LambdaOpt *>* opt_list = this->optlist;
            for (std::vector<LambdaOpt *>::iterator it = opt_list->begin();
                it != opt_list->end(); ++it) {

                // Create label for every option
                std::string opt_label = get_next_label();
                ArgumentConst *opt_arg = new ArgumentConst(opt_label, NULL);
                Quad *opt_quad = new Quad("label", NULL, NULL, opt_arg);
                case_quad->appendToFinal(opt_quad);

                // Generate argument for expression inside option
                Quad *exp_opt = (*it)->getOpt()->genCode();
                Argument *result_arg = exp_opt->getResult();
                tests->appendToFinal(exp_opt);

                // Fill quad list of comparisons
                tests->appendToFinal(new Quad("beq", var_arg, result_arg, opt_arg));

                // Generate code for every case
                case_quad->appendToFinal((*it)->genCode(exit_arg));
            }

            // Test label
            Quad *test_quad = new Quad("label", NULL, NULL, test_arg);
            case_quad->appendToFinal(test_quad);

            // List of options
            case_quad->appendToFinal(tests);

            // Quad for otherwise
            Quad *othw_quad = this->otherwise->genCode();
            case_quad->appendToFinal(othw_quad);

            // Exit label
            Quad *exit_quad = new Quad("label", NULL, NULL, exit_arg);
            case_quad->appendToFinal(exit_quad);

            case_quad->appendToFinal(last_comment);
            return case_quad;
        }
};

#endif

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
  * Misc functions to aid interm code generationc
  */

#include <string>
#include "interm_code_helper.hh"
#include "../symtable/symbol.hh"

Symbol *get_next_temp() {
    int next = next_temp++;
    std::string id = "$t" + std::to_string(next);
    Symbol *next_temp_symbol = new Symbol(id,0,0,0);
    return next_temp_symbol;
}

std::string get_next_label() {
    int next = next_label++;
    std::string label = "@L" + std::to_string(next);
    return label;
}

void gen_un_op(Quad *q, std::string un_op) {
    if (un_op == "-" || un_op == "!") {
        Symbol *temp = get_next_temp();
        Argument *result = new ArgumentVar(temp, q->getResult()->getType());

        Quad *next = new Quad(un_op, q->getResult(), NULL, result);

        q->appendToFinal(next);
    }
}

std::vector<BasicBlock *> *genBasicBlocks(Quad *q) {
    Quad *first = q;
    Quad *last = q;


    std::vector<BasicBlock *> *blocks = new std::vector<BasicBlock *>;

    while (last->getNext() != NULL) {
        if (last->getOp() == "goto" || last->getOp() == "<" || last->getOp() == "<=" ||
               last->getOp() == ">" || last->getOp() == ">=" ||
               last->getOp() == "==" || last->getOp() == "!=" || last->getOp() == "call") {
            if (last->getOp() == "call" && last->getArg1()->toString() == "escribir") {
                last = last->getNext();
                continue;
            } else {
                // There's a block from first to last
                blocks->push_back(new BasicBlock(first, last));

                first = last->getNext();
                last = first;
                continue;
            }
        } else if (last->getNext()->getOp() == "label") {
            // There's a block from first to last
            blocks->push_back(new BasicBlock(first, last));

            first = last->getNext();
            last = first;
            continue;
        } else {
            last = last->getNext();
        }
    }

    // Coming out of the loop there's a block from first to last
    blocks->push_back(new BasicBlock(first, last));

    return blocks;
}

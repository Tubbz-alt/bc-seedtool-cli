//
//  format-dice.cpp
//
//  Copyright © 2020 by Blockchain Commons, LLC
//  Licensed under the "BSD-2-Clause Plus Patent License"
//

#include "format-dice.hpp"
#include "params.hpp"
#include "utils.hpp"
#include "random.hpp"

void FormatDice::process_input(Params* p) {
    auto input = p->get_one_argument();
    auto entropy = digits_to_data(input, 1, 6);
    p->seed = deterministic_random(entropy, p->count);
}

void FormatDice::process_output(Params* p) {
    p->output = data_to_ints(p->seed, 1, 6, "");
}

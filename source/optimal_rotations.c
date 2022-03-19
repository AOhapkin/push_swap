#include "push_swap.h"

void ra_rb_optimization(t_rotations* rotations)
{
    if (rotations->ra < rotations->rb)
    {
        rotations->rb = rotations->rb - rotations->ra;
        rotations->ra = 0;
    }
    else
    {
        rotations->ra = rotations->ra - rotations->rb;
        rotations->rb = 0;
    }
    rotations->rra = 0;
    rotations->rrb = 0;
    rotations->rrr = 0;
}

void rra_rrb_optimization(t_rotations* rotations)
{
    if (rotations->rra < rotations->rrb)
    {
        rotations->rrb = rotations->rrb - rotations->rra;
        rotations->rra = 0;
    }
    else
    {
        rotations->rra = rotations->rra - rotations->rrb;
        rotations->rrb = 0;
    }
    rotations->ra = 0;
    rotations->rb = 0;
    rotations->rr = 0;
}

void ra_rrb_optimization(t_rotations* rotations)
{
    rotations->rb = 0;
    rotations->rra = 0;
    rotations->rrr = 0;
    rotations->rr = 0;
}

void rra_rb_optimization(t_rotations* rotations)
{
    rotations->ra = 0;
    rotations->rrb = 0;
    rotations->rrr = 0;
    rotations->rr = 0;
}

void set_operations_to_rotations(t_rotations *rotations, int variation_index)
{
    void (*optimisation_functions[NUM_OF_OPERATIONS])(t_rotations *not_optimized);

    optimisation_functions[RA_RB] = ra_rb_optimization;
    optimisation_functions[RRA_RRB] = rra_rrb_optimization;
    optimisation_functions[RA_RRB] = ra_rrb_optimization;
    optimisation_functions[RRA_RB] = rra_rb_optimization;
    optimisation_functions[variation_index](rotations);
}

void optimize_rotations(t_rotations *rotations) {
    int		r[NUM_VARIATIONS];
    int     optimal;

    r[RA_RB] = max(rotations->ra, rotations->rb);
    r[RRA_RRB] = max(rotations->rra, rotations->rrb);
    r[RA_RRB] = rotations->ra + rotations->rrb;
    r[RRA_RB] = rotations->rra + rotations->rb;
    set_operations_to_rotations(rotations, get_index_smallest_value(r, NUM_VARIATIONS));
}
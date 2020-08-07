//function ximpliedDerivative(f, appendix)
argument[2] = fun_getArgOne(argument[0]);
argument[3] = fun_getArgTwo(argument[0]);

//if (fun_equal(f,appendix))
//{
//    return new fun_const(0);
//}

switch(fun_getType(argument[0]))
{
    case 1: //fun_x
        return fun_const(1);
        break;
    case 2: //fun_y
        return fun_const(0);
        break;
    case 3: //fun_z
        return fun_const(0);
        break;
    case 4: //fun_const
        return fun_const(0);
        break;
    case 5: //fun_add
        return fun_add(fun_xImpliedDerivative(argument[2],argument[1]),fun_xImpliedDerivative(argument[3],argument[1]));
        break
    case 6: //fun_subt
        return fun_subt(fun_xImpliedDerivative(argument[2],argument[1]),fun_xImpliedDerivative(argument[3],argument[1]));
        break
    case 7: //fun_mult
        return fun_add(fun_mult(fun_xImpliedDerivative(argument[2],argument[1]),argument[3]),fun_mult(argument[2],fun_xImpliedDerivative(argument[3],argument[1])));
        break
    case 8: //fun_div
        return fun_div(fun_subt(fun_mult(argument[3],fun_xImpliedDerivative(argument[2],argument[1])),fun_mult(argument[2],fun_xImpliedDerivative(argument[3],argument[1]))),fun_mult(argument[3],argument[3]));
        break
    case 9: //fun_sin
        return fun_mult(fun_xImpliedDerivative(argument[2],argument[1]),fun_cos(argument[2]));
        break
    case 10: //fun_cos
        return fun_mult(fun_xImpliedDerivative(argument[2],argument[1]),fun_mult(fun_const(-1),fun_sin(argument[2])));
        break
    case 11: //fun_floor
        return fun_div(fun_subt(argument[2],fun_floor(argument[2])),fun_subt(argument[2],fun_floor(argument[2])));
        break
}

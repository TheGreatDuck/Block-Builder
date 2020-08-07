//fun_eval(f,x,y,z)
switch(fun_getType(argument[0]))
{
    case 1: //fun_x
        return argument[1];
        break;
    case 2: //fun_y
        return argument[2];
        break;
    case 3: //fun_z
        return argument[3];
        break;
    case 4: //fun_const
        return fun_getArgOne(argument[0]);
        break;
    case 5: //fun_add
        return (fun_eval(fun_getArgOne(argument[0]),argument[1],argument[2],argument[3]) + fun_eval(fun_getArgTwo(argument[0]),argument[1],argument[2],argument[3]));
        break;
    case 6: //fun_subt
        return (fun_eval(fun_getArgOne(argument[0]),argument[1],argument[2],argument[3]) - fun_eval(fun_getArgTwo(argument[0]),argument[1],argument[2],argument[3]));
        break;
    case 7: //fun_mult
        return (fun_eval(fun_getArgOne(argument[0]),argument[1],argument[2],argument[3]) * fun_eval(fun_getArgTwo(argument[0]),argument[1],argument[2],argument[3]));
        break;
    case 8: //fun_div
        return (fun_eval(fun_getArgOne(argument[0]),argument[1],argument[2],argument[3]) / fun_eval(fun_getArgTwo(argument[0]),argument[1],argument[2],argument[3]));
        break;
    case 9: //fun_sin
        return sin(fun_eval(fun_getArgOne(argument[0]),argument[1],argument[2],argument[3]));
        break;
    case 10: //fun_cos
        return cos(fun_eval(fun_getArgOne(argument[0]),argument[1],argument[2],argument[3]));
        break;
    case 11: //fun_floor
        return floor(fun_eval(fun_getArgOne(argument[0]),argument[1],argument[2],argument[3]));
        break;
}

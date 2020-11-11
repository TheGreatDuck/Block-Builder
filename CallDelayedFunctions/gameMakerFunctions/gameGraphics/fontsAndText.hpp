#ifdef DEFINE_WRAPPERS
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(draw_text)
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void draw_text(int x, int y, const char* text_string);
#ifdef DEFINE_WRAPPERS
void draw_text(int x, int y, const char* text_string)
{
    addDelayedFunctionCall(FP_draw_text, 0, x, y, text_string);
}
#endif

/*draw_set_font(font)
draw_set_halign(halign)

        fa_left
        fa_center
        fa_right

draw_set_valign(valign)

        fa_top
        fa_middle
        fa_bottom*/

//draw_text_ext(int x, int y, char* string, int sep, int w)
//string_width(char* string)
//string_height(char* string)
//string_width_ext(char* string, int sep, int w)
//string_height_ext(char* string, int sep, int w)

/*draw_text_transformed(int x, int y, char* string, int xscale, int yscale, int angle)
draw_text_ext_transformed(x,y,string,sep,w,xscale,yscale,angle)
draw_text_color(x,y,string,c1,c2,c3,c4,alpha)
draw_text_ext_color(x,y,string,sep,w,c1,c2,c3,c4,alpha)
draw_text_transformed_color(x,y,string,xscale,yscale,angle,c1,c2,c3,c4,alpha)
draw_text_ext_transformed_color(x,y,string,sep,w,xscale,yscale,angle,c1,c2,c3,c4, double alpha)*/

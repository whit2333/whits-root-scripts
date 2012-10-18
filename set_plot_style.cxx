/*! Functions to create color palette and add new colors.
    Also see color_scheme.cxx
 */

void add_new_colors();
void create_colors_3000();
void set_plot_style(const Int_t NCont = 99);
//_____________________________________________________________________________________

void set_plot_style(const Int_t NCont)
{
    const Int_t NRGBs = 5;
    Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
    Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
    Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
    Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
    TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
    gStyle->SetNumberContours(NCont);
}
//_____________________________________________________________________________________

void add_new_colors()
{
   Int_t ci = 2000;
   TColor *color = new TColor(ci, 255.0/255.0, 53.0/255.0, 0.0, "red-ish",0.9); // alpha = 0.5
   ci++;
   TColor *color = new TColor(ci, 9.0/255.0, 105.0/255.0, 162.0/255.0, "blue-ish", 0.9);
   ci++;
   TColor *color = new TColor(ci, 255.0/255.0, 140.0/255.0, 0.0, "orange-ish",0.9); 
   ci++;
   TColor *color = new TColor(ci, 0.0, 182.0/255.0, 79.0/255.0 , "green-ish",0.9); 
   ci++;
   TColor *color = new TColor(ci, 0.1, 0.1, 0.1, "",0.9);
   ci++;
   TColor *color = new TColor(ci, 0.1, 0.1, 0.1, "",0.9);
   ci++;
}
//_____________________________________________________________________________________

/**  Color Palette by Color Scheme Designer
     Palette URL: http://colorschemedesigner.com/#3P62gVWjFv5IX
     Color Space: RGB; 
*** Primary Color:
   var. 1 = #021A6A = rgb(2,26,106)
   var. 2 = #152250 = rgb(21,34,80)
   var. 3 = #011146 = rgb(1,17,70)
   var. 4 = #4F6ED5 = rgb(79,110,213)
   var. 5 = #8B9CD5 = rgb(139,156,213)
*** Secondary Color A:
   var. 1 = #410169 = rgb(65,1,105)
   var. 2 = #38144F = rgb(56,20,79)
   var. 3 = #2A0045 = rgb(42,0,69)
   var. 4 = #A04ED5 = rgb(160,78,213)
   var. 5 = #B88AD5 = rgb(184,138,213)
*** Secondary Color B:
   var. 1 = #007031 = rgb(0,112,49)
   var. 2 = #155530 = rgb(21,85,48)
   var. 3 = #004A20 = rgb(0,74,32)
   var. 4 = #4DD789 = rgb(77,215,137)
   var. 5 = #8BD7AC = rgb(139,215,172)
*** Complementary Color:
   var. 1 = #9D6C00 = rgb(157,108,0)
   var. 2 = #775B1D = rgb(119,91,29)
   var. 3 = #674700 = rgb(103,71,0)
   var. 4 = #E3B652 = rgb(227,182,82)
   var. 5 = #E3CA93 = rgb(227,202,147)
#####  Generated by Color Scheme Designer (c) Petr Stanicek 2002-2010
 */
void create_colors_3000(){
   Int_t ci = 3000;
   /// Primary
   create_color(ci,2,26,106); ci++;
   create_color(ci,21,34,80); ci++;
   create_color(ci,1,17,70); ci++;
   create_color(ci,79,110,213); ci++;
   create_color(ci,139,156,213); ci++;
   /// Complementary
   create_color(ci,157,108,0); ci++;
   create_color(ci,119,91,29); ci++;
   create_color(ci,103,71,0); ci++;
   create_color(ci,227,182,82); ci++;
   create_color(ci,227,202,147); ci++;
   /// Secondary Color A
   create_color(ci,65,1,105); ci++;
   create_color(ci,56,20,79); ci++;
   create_color(ci,42,0,69); ci++;
   create_color(ci,160,78,213); ci++;
   create_color(ci,184,138,213); ci++;
   /// Secondary Color B
   create_color(ci,0,112,49); ci++;
   create_color(ci,21,85,48); ci++;
   create_color(ci,0,74,32); ci++;
   create_color(ci,77,215,137); ci++;
   create_color(ci,139,215,172); ci++;

}
//_____________________________________________________________________________________


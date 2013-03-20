/** Functions used in creating nice looking color schemes.
    Color instead of using the normal RGB color wheel (where red, blue,
    and green are separated by 120 degrees), color schemes look much 
    better when using the RYB color wheel (where red and green are now
    180 degrees apart). 
    From http://ultrahigh.org/2007/08/20/making-pretty-root-color-palettes/
 */
//_____________________________________________________________________________________

/** Creates and sets the a new color scheme.   
    Accented analogic (primary color, color A = Hue +angle , color B = Hue - angle, 
    complementary = Hue + 180degrees.
 */
Int_t set_color_scheme(Float_t angle , Int_t rp , Int_t gp , Int_t bp, Int_t startIndex );

/** Creates some default color schemes. */
void color_scheme();

/** Inverts the RGB color  by taking r_new = 1.0-R, etc... */
void invert_RGB(Float_t R, Float_t G, Float_t B, Float_t& r_new, Float_t& g_new, Float_t& b_new);

void create_color(Int_t num, Int_t r, Int_t g, Int_t b);
void create_color_HLS(Int_t num, Float_t h, Float_t l, Float_t s); 
void create_color_RGB(Int_t num, Float_t r, Float_t g, Float_t b);

/** Draws colors starting at firstcolor.
 */
TCanvas* draw_colors(Int_t firstcolor = 4000);

/** Converts the hue value in RGB to a hue value in RYB.
    From  http://www.paintassistant.com/rybrgb.html 
 */
Float_t RGBHue_to_RYBHue(Float_t Hrgb);

/** Converts the hue value in RYB to a hue value in RGB.
 */ 
Float_t RYBHue_to_RGBHue(Float_t Hryb);


/** Returns the number of colors created.
 */
Int_t set_color_scheme(Float_t angle = 30, Int_t rp = 255 , Int_t gp = 0, Int_t bp = 0 , Int_t startIndex = 4000);

//_____________________________________________________________________________________
void color_scheme(){
   Int_t ncol = 0;
   ncol = set_color_scheme();
   draw_colors(4000);
   ncol = set_color_scheme(29.0,255.0*0.89,0.0,255.0*0.65,4000+ncol);
   draw_colors(4000+ncol);
   ncol = set_color_scheme(26.0,0.0, 255.0*0.76, 255.0*0.83,4000+2*ncol);
   draw_colors(4000+ncol*2);
}
//_____________________________________________________________________________________

TCanvas * draw_colors(Int_t firstcolor)
{
   // Static function to Display Color Table in a pad.

   Int_t i, j;
   Int_t color;
   Double_t xlow, ylow, xup, yup, hs, ws;
   Double_t x1, y1, x2, y2;
   x1 = y1 = 0;
   x2 = y2 = 20;

   Int_t NX = 4;
   Int_t NY = 6;

   TCanvas * c = new TCanvas();
   c->cd(0);

   gPad->SetFillColor(0);
   gPad->Clear();
   gPad->Range(x1,y1,x2,y2);

   TText *text = new TText(0,0,"");
   text->SetTextFont(61);
   text->SetTextSize(0.07);
   text->SetTextAlign(22);

   TBox *box = new TBox();

   // Draw color table boxes.
   hs = (y2-y1)/Double_t(NY);
   ws = (x2-x1)/Double_t(NX);
   for (i=0;i<NX;i++) {
      xlow = x1 + ws*(Double_t(i)/*+0.1*/);
      xup  = x1 + ws*(Double_t(i)+1.0/*+0.9*/);
      for (j=0;j<NY;j++) {
         ylow = y1 + hs*(Double_t(j)/*+0.1*/);
         yup  = y1 + hs*(Double_t(j)+1.0/*+0.9*/);
         color = firstcolor + NX*j + i;
         box->SetFillStyle(1001);
         box->SetFillColor(color);
         box->DrawBox(xlow, ylow, xup, yup);
//          box->SetFillStyle(0);
//          box->SetLineColor(1);
//          box->SetLineSize(0);
//          box->DrawBox(xlow, ylow, xup, yup);
         if (color == 1) text->SetTextColor(0);
         else            text->SetTextColor(1);
         text->DrawText(0.5*(xlow+xup), 0.5*(ylow+yup), Form("%d",color));
      }
   }
   return(c);
}

//_____________________________________________________________________________________
void create_color(Int_t num, Int_t r, Int_t g, Int_t b){
   TColor *color = new TColor(num, (float)r/255.0, (float)g/255.0,(float)b/255.0, Form("%d-%d-%d-ish",r,g,b) );//,1);
}

//_____________________________________________________________________________________
void create_color_RGB(Int_t num, Float_t r, Float_t g, Float_t b) {
//    std::cout << " Creating color " << num << " with ";
//    std::cout << " R=" << r << ", G=" << g << ", B=" << b << std::endl;
   TColor *color = new TColor(num, (float)r , (float)g,(float)b, Form("%d-%d-%d-ish",r,g,b) );//,0.9);
}

//_____________________________________________________________________________________
void create_color_HLS(Int_t num, Float_t h, Float_t l, Float_t s){
//    std::cout << " Creating color " << num << " with ";
//    std::cout << "Hue=" << h << ", Lightness=" << l << ", Saturation=" << s << std::endl;
   Float_t r,g,b;
   TColor::HLS2RGB(h,l,s,r,g,b);
   create_color_RGB(num,r,g,b);
}

//_____________________________________________________________________________________
void invert_RGB(Float_t R, Float_t G, Float_t B, Float_t& r_new, Float_t& g_new, Float_t& b_new) {
     r_new = 1.0 - R;
     g_new = 1.0 - G;
     b_new = 1.0 - B;
}

//_____________________________________________________________________________________
Int_t set_color_scheme(Float_t angle , Int_t rp , Int_t gp , Int_t bp, Int_t startIndex )
{
   Float_t R,G,B,H,L,S;

   R = (double)rp/255.0;
   G = (double)gp/255.0;
   B = (double)bp/255.0;

   Int_t ci = startIndex;
   TColor *color = 0;
   Float_t newAngle = 0;
   Float_t Hryb = 0;
   Float_t Hrgb = 0;

   /// Primary Color
   TColor::RGB2HLS(R,G,B, H, L, S);
   create_color_HLS(ci,H,L,S); ci++;
   //color = new TColor(ci, R,B,G, "primary color" ,0.5); 

   /// Secondary Color A
   Hryb = RGBHue_to_RYBHue(H);
   newAngle = (double)(((int)(Hryb+angle))%360);
   Hrgb = RYBHue_to_RGBHue(newAngle);
   create_color_HLS(ci,Hrgb,L,S); ci++;

   /// Secondary Color B
   Hryb = RGBHue_to_RYBHue(H);
   newAngle = (double)(((int)(Hryb-angle+360.0))%360);
   Hrgb = RYBHue_to_RGBHue(newAngle);
   create_color_HLS(ci,Hrgb,L,S); ci++;

   /// Complementary Color
   Hryb = RGBHue_to_RYBHue(H);
   newAngle = (double)(((int)(Hryb+180.0))%360);
   Hrgb = RYBHue_to_RGBHue(newAngle);
   create_color_HLS(ci,Hrgb,L,S); ci++;

   for(int i = 0 ;i<4 ;i ++ ) {
      Double_t Dl = 0.2 + (double)i*0.2;
      for(int j = 0; j<4 ;j++){
         color = gROOT->GetColor(startIndex+j);
         color->GetHLS(H,L,S);
         create_color_HLS(ci,H,Dl,S);
         ci++;

      }
   }
   return(ci-startIndex);
}
//_____________________________________________________________________________________

Float_t RGBHue_to_RYBHue(Float_t Hrgb){
   if( !(Hrgb >= 0.0 && Hrgb<=360.0) ) Hrgb = (double)(((int)(Hrgb+5*360))%360);
   if(Hrgb >=0.0 && Hrgb < 120.0) return(Hrgb*180.0/120.0);
   else if(Hrgb >=120.0 && Hrgb < 240.0) return((Hrgb-120.0)*60.0/120.0 +180.0);
   else if(Hrgb >=240.0 && Hrgb <= 360.0) return((Hrgb-240.0)*120.0/120.0 +240.0);
   else return(0.0);
}

Float_t RYBHue_to_RGBHue(Float_t Hryb){
   if( !(Hryb >= 0.0 && Hryb<=360.0) ) Hryb = (double)(((int)(Hryb+5*360))%360);
   if(Hryb >=0.0 && Hryb < 180.0) return(Hryb*120.0/180.0);
   else if(Hryb >=180.0 && Hryb < 240.0) return((Hryb-180.0)*120.0/60.0 +120.0);
   else if(Hryb >=240.0 && Hryb <= 360.0) return((Hryb-240.0)*120.0/120.0 + 240.0);
   else return(0.0);
}

/*
void RGB2XYZ(Float_t R, Float_t G, Float_t B, Float_t& X, Float_t& Y, Float_t& Z){
   Float_t var_R = R; //( R / 255.0 )        //R from 0 to 255
   Float_t var_G = G;//( G / 255.0 )        //G from 0 to 255
   Float_t var_B = B;//( B / 255.0 )        //B from 0 to 255
   
	if ( var_R > 0.04045 ) var_R = TMath::Power( ( ( var_R + 0.055 ) / 1.055 ) , 2.4);
	else                   var_R = var_R / 12.92; 
		if ( var_G > 0.04045 ) var_G = TMath::Power(( ( var_G + 0.055 ) / 1.055 ) , 2.4)
		else                   var_G = var_G / 12.92;
			if ( var_B > 0.04045 ) var_B = TMath::Power( ( ( var_B + 0.055 ) / 1.055 ) < 2.4);
			else                   var_B = var_B / 12.92;

				var_R = var_R * 100;
					var_G = var_G * 100;
					var_B = var_B * 100;

					//Observer. = 2°, Illuminant = D65OA
					X = var_R * 0.4124 + var_G * 0.3576 + var_B * 0.1805;
					Y = var_R * 0.2126 + var_G * 0.7152 + var_B * 0.0722;
					Z = var_R * 0.0193 + var_G * 0.1192 + var_B * 0.9505;
}

void XYZ2Lab(Float_t X, Float_t Y, Float_t Z, Float_t& L, Float_t& a, Float_t& b){
var_X = X / ref_X          //ref_X =  95.047   Observer= 2°, Illuminant= D65
var_Y = Y / ref_Y          //ref_Y = 100.000
var_Z = Z / ref_Z          //ref_Z = 108.883

if ( var_X > 0.008856 ) var_X = var_X ^ ( 1/3 )
	else                    var_X = ( 7.787 * var_X ) + ( 16 / 116 )
	if ( var_Y > 0.008856 ) var_Y = var_Y ^ ( 1/3 )
	else                    var_Y = ( 7.787 * var_Y ) + ( 16 / 116 )
	if ( var_Z > 0.008856 ) var_Z = var_Z ^ ( 1/3 )
	else                    var_Z = ( 7.787 * var_Z ) + ( 16 / 116 )

	CIE-L* = ( 116 * var_Y ) - 16
	CIE-a* = 500 * ( var_X - var_Y )
	CIE-b* = 200 * ( var_Y - var_Z )
*/


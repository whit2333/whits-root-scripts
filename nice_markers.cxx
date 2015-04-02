// 
// Arrays of nice attrigbutes to be used in loops.
// 

std::vector<int> gNiceMarkerStyle;
std::vector<int> gNiceColors;
std::vector<int> gNiceLineStyle;
Int_t            gNiceFont = 132; //times-medium-r-normal 

void nice_colors() {
   gNiceColors.push_back(kRed+1);  // darker red
   gNiceColors.push_back(kBlue+1); // darker blue
   gNiceColors.push_back(kGreen+1);
   gNiceColors.push_back(kCyan+1); 
   gNiceColors.push_back(kMagenta+1);       
   gNiceColors.push_back(kOrange+2);       
   gNiceColors.push_back(kYellow-3);       
   gNiceColors.push_back(kRed);    
   gNiceColors.push_back(kRed);    
   gNiceColors.push_back(kRed);    
   gNiceColors.push_back(kRed);    
   gNiceColors.push_back(kRed);    
   gNiceColors.push_back(kRed);    
   gNiceColors.push_back(kRed);    
}

void nice_markers() {
   // filled markers:
   gNiceMarkerStyle.push_back(20); // circle
   gNiceMarkerStyle.push_back(21); // square
   gNiceMarkerStyle.push_back(22); // triangle
   gNiceMarkerStyle.push_back(23); // upside down triangle
   gNiceMarkerStyle.push_back(34); // cross
   gNiceMarkerStyle.push_back(29); // star
   gNiceMarkerStyle.push_back(33); // diamond
   // open
   gNiceMarkerStyle.push_back(24); // circle
   gNiceMarkerStyle.push_back(25); // square
   gNiceMarkerStyle.push_back(26); // triangle
   gNiceMarkerStyle.push_back(32); // upside down triangle
   gNiceMarkerStyle.push_back(30); // star
   gNiceMarkerStyle.push_back(27); // diamond
   gNiceMarkerStyle.push_back(28); // cross
}

void view_color_wheel(){
   TCanvas * c = new TCanvas();
   TColorWheel *w = new TColorWheel();
   w->SetCanvas(c);
   w->Draw();
   c->SaveAs("plots/color_wheel.png");
}


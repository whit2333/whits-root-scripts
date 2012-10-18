/**  Whitney Armstrong (whit@temple.edu)
 * 
 *   Uses scripts found in $HOME/src/
 *
 *   set_plot_style.cxx - 
 *      This script sets up a nice look color palette
 *   
 *  
 *
 */
{
   //gStyle->Reset();
   gErrorIgnoreLevel=1001; // Ignore Info
   // gErrorIgnoreLevel=2001; // Ignore Warnings
   //gSystem->Load("libMinuit2.so");
   gSystem->Load("libFoam");
   gSystem->Load("libTreeViewer");
   gSystem->Load("libEG");
   gSystem->Load("libPythia6"); // this has to be loaded before libInSANE ... don't know why
   //gSystem->Load("libEGPythia6");

   /// InSANE Libraries
   gSystem->AddIncludePath("-I$InSANEDIR/include");
   gSystem->AddIncludePath("-I$InSANEDIR/main"); // for generated ANNs
   gSystem->Load("libInSANE.so");
   gROOT->SetMacroPath(Form("%s:%s/main/scripts",gROOT->GetMacroPath(),gSystem->Getenv("InSANEDIR")));


   /// WEvents Libraries
   gSystem->AddIncludePath("-I${WEVENTSDIR}/include");
   gSystem->Load("${WEVENTSDIR}/lib/libWG4.so");

   /// NucDB Libraries
   gSystem->AddIncludePath(" -I$NucDB_DIR/include ");
   gSystem->Load("$NucDB_DIR/lib/libNucDB.so");

   /// Frequently used pointers

   SANERunManager      * rman = SANERunManager::GetRunManager();
   SANEAnalysisManager * aman = SANEAnalysisManager::GetAnalysisManager();
   //aman->SetupFolders();
   rman->SetVerbosity(1);

   /// Geant4 libraries from GEANT4 VMC
   //gROOT->LoadMacro("/usr/local/geant4_vmc/examples/macro/basiclibs.C");
   //basiclibs();
   //  gROOT->LoadMacro("/usr/local/geant4_vmc/examples/macro/g4libs.C");
   //  g4libs();

   /// STYLE
   gROOT->SetStyle("Modern");
   /// load some useful scripts Creates a nice color palette
   gROOT->LoadMacro(Form("%s/src/set_plot_style.cxx",gSystem->Getenv("HOME") ) );
   gROOT->LoadMacro(Form("%s/src/color_scheme.cxx",gSystem->Getenv("HOME") ) );

   /// Turn off some borders
   gStyle->SetCanvasBorderMode(0);
   gStyle->SetFrameBorderMode(0);
   gStyle->SetPadBorderMode(0);
   gStyle->SetDrawBorder(0);
   gStyle->SetCanvasBorderSize(0);
   gStyle->SetFrameBorderSize(0);
   gStyle->SetPadBorderSize(0);
   gStyle->SetTitleBorderSize(0);

   gStyle->SetAxisColor(1, "xyz");
   gStyle->SetCanvasColor(0);
   gStyle->SetFrameFillColor(0);
   gStyle->SetFrameLineColor(1);
   gStyle->SetHistFillColor(0);
   gStyle->SetHistLineColor(1);
   //gStyle->SetPadColor(1);
   gStyle->SetPadColor(kWhite);
   gStyle->SetTitleColor(1);
   gStyle->SetTitleTextColor(1);
   gStyle->SetLabelColor(1,"xyz");


   /// Set the size of the default canvas
   gStyle->SetCanvasDefH(800);
   gStyle->SetCanvasDefW(800*1.618);
   //gStyle->SetCanvasDefX(10);
   //gStyle->SetCanvasDefY(10);

   /// Text font code = 10*fontnumber + precision
   // Fonts:  Helvetica (42), upright, normal
   //int style_label_font=42;


   /// Axes Numbers are called "Labels"
   //gStyle->SetLabelFont(style_label_font,"xyz");
   gStyle->SetLabelSize(0.035,"xyz");
   gStyle->SetLabelOffset(0.007,"xyz");
   gStyle->SetTitleSize(0.04,"xyz"); // axis titles
   gStyle->SetTitleOffset(1.0000,"xyz");
   gStyle->SetStripDecimals(kFALSE); // if we have 1.5 do not set 1.0 -> 1
   TGaxis::SetMaxDigits(3); // restrict the number of digits in labels
   gStyle->SetLabelColor(1,"xyz");

   //gStyle->SetStatFont(style_label_font);
   //gStyle->SetTitleFont(style_label_font,"xyz"); // axis titles

   // Histogram's Main Title
   //gStyle->SetTitleFont(style_label_font,"h"); // histogram title
   //gStyle->SetTitleSize(0.05,"h"); // histogram title
   //gStyle->SetTitleH(0.1);
   //gStyle->SetTitleX(0.12); // spot where histogram title goes
   //gStyle->SetTitleY(0.99); // spot where histogram title goes
   //gStyle->SetTitleW(0.78); // width computed so that title is centered


   /// Marker Style
   gStyle->SetEndErrorSize(4);
   gStyle->SetErrorX(0.0);

   /// Set Line Widths
   gStyle->SetFrameLineWidth(2);
   gStyle->SetHistLineWidth(2);

   /// Show functions in blue(4)
   gStyle->SetFuncColor(1);
   gStyle->SetFuncStyle(10);
   gStyle->SetFuncWidth(2);

   /// Set all fill styles to be empty and line styles to be solid
   gStyle->SetFrameFillStyle(0);
   gStyle->SetHistFillStyle(1001);
   gStyle->SetFrameLineStyle(0);
   gStyle->SetHistLineStyle(0);
   gStyle->SetTitleStyle(0);
   gStyle->SetFuncStyle(1);

   /// Set margins 
   gStyle->SetPadTopMargin(0.09);
   gStyle->SetPadBottomMargin(0.09);
   gStyle->SetPadLeftMargin(0.09);
   gStyle->SetPadRightMargin(0.09);

   /// Log axes
   gStyle->SetOptLogx(0);
   gStyle->SetOptLogy(0);
   gStyle->SetOptLogz(0);

   /// Set Data/Stat/... and other options
   gStyle->SetStatColor(0);
   gStyle->SetStatTextColor(1);
/*   gStyle->SetFitFormat("6.4e");*/
   gStyle->SetOptDate(0);
   gStyle->SetDateX(0.01);
   gStyle->SetDateY(0.01);
   gStyle->SetOptFile(0);

   gStyle->SetOptFit(111);
/*   gStyle->SetOptStat(1110);// no histogram title*/

//   gStyle->SetOptStat(0);// no stats
   gStyle->SetOptStat(10);// no histogram title
/*   gStyle->SetStatFormat("6.4e");*/
/*   gStyle->SetStatStyle(0); // hollow*/
/*   gStyle->SetStatStyle(1001); // filled*/
   gStyle->SetStatStyle(0); // hollow
   gStyle->SetStatBorderSize(0);
   gStyle->SetStatW(0.20);
   gStyle->SetStatH(0.125);
   //gStyle->SetStatX(0.90);
   //gStyle->SetStatY(0.90);
   gStyle->SetStatX(1.0-gStyle->GetPadRightMargin()-0.01);
   gStyle->SetStatY(1.0-gStyle->GetPadTopMargin()-0.01);

   gStyle->SetOptTitle(1);

   /// Set tick marks and turn off grids
   //gStyle->SetNdivisions(1005,"xyz");
   //gStyle->SetNdivisions(510,"xyz");
   gStyle->SetPadTickX(1);
   gStyle->SetPadTickY(1);
   gStyle->SetTickLength(0.02,"xyz");
   gStyle->SetPadGridX(1);
   gStyle->SetPadGridY(1);

   /// no supressed zeroes!
   gStyle->SetHistMinimumZero(kTRUE);

   /// Set paper size for life in the US
   gStyle->SetPaperSize(TStyle::kUSLetter);
   // or europe
   //gStyle->SetPaperSize(TStyle::kA4);

   /// Uncommenting this leads to weird font behavior (especially for small text)....
   //gStyle->SetCanvasPreferGL(kTRUE); 

   /// Force this style on all histograms
   //gROOT->ForceStyle();

   /// use a pretty palette for color plots
   gStyle->SetPalette(1,0);
   set_plot_style();

   /// Add new colors starting at 1000
   add_new_colors();
   create_colors_3000();
   set_color_scheme(26.0,0.0, 255.0*0.76, 255.0*0.83,4000);

//   set_color_scheme();

   //gStyle->SetOptLogz(0);
   //  if ncolors <= 0 a default palette (see below) of 50 colors is defined. 
   //  The colors defined in this palette are OK for coloring pads, labels.
   //  if ncolors == 1 && colors == 0, then a Pretty Palette with a Spectrum Violet->Red is created. 
   //  It is recommended to use this Pretty palette when drawing legos, surfaces or contours.
   //  if ncolors > 50 and colors=0, the DeepSea palette is used. 
   // (see TColor::CreateGradientColorTable for more details)
   // if ncolors > 0 and colors = 0, the default palette is used with a maximum of ncolors. 
   // make sure to include headers from my home are
   // gStyle->SetPalette(/*int ncolors*/1,/*int * colors*/0);


   // this allows you to use multiple root versions on the same system
   // without libraries constantly being recompiled.
   TString dirname = gROOT->GetVersion();
   dirname.ReplaceAll(".","_");
   dirname.ReplaceAll("/","_");
   dirname.Append("_libs");
   TString appname(gApplication->Argv(0));
   if(appname.Contains("loon")){
      appname="loon";
   }
   else appname="root";
   appname+="_";
   dirname.Prepend(appname);
   dirname.Prepend("/root_build/"); // base dir for compliled macros
   dirname.Prepend(gSystem->Getenv("HOME"));
   //cout<<"Setting build directory to: "<<dirname<<endl;
   //gSystem->mkdir(dirname.Data(),true); // make dir if it doesn't exist
   //gSystem->SetBuildDir(dirname);



}

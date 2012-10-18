#print 'o  Found .rootlogon.py !!!'
import os
from ROOT import gROOT,gSystem,gStyle
gSystem.Load( 'libFoam' )
gSystem.Load( 'libTreeViewer' )
gSystem.Load( 'libInSANE' )
gSystem.Load( 'libNucDB' )
gStyle.SetStatColor(0)
gStyle.SetCanvasColor(0)
gStyle.SetPadColor(0)
gStyle.SetPadBorderMode(0)
gStyle.SetCanvasBorderMode(0)
gStyle.SetFrameBorderMode(0)
gStyle.SetOptStat(1110)
gStyle.SetStatH(0.2)
gStyle.SetStatW(0.2)
gStyle.SetStatX(0.99)
gStyle.SetTitleColor(1)
gStyle.SetTitleFillColor(0)
gStyle.SetTitleY(1.)
gStyle.SetTitleX(.15)
gStyle.SetTitleBorderSize(0)
gStyle.SetPadTickX(1)
gStyle.SetPadTickY(1)
gStyle.SetPalette(1)

#def set_plot_style():
    #NRGBs = 5
    #NCont = 255
    #stops = array([ 0.00, 0.34, 0.61, 0.84, 1.00 ])
    #red = array([ 0.00, 0.00, 0.87, 1.00, 0.51 ])
    #green = ([ 0.00, 0.81, 1.00, 0.20, 0.00 ])
    #blue = ([ 0.51, 1.00, 0.12, 0.00, 0.00 ])
    #TColor.CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont)
    #gStyle.SetNumberContours(NCont)
#}
#gROOT.Macro( os.path.expanduser( '~/.rootlogon.C' ) )
#gROOT.LoadMacro( gSystem.Getenv('HOME') + '/src/set_plot_style.cxx')

#print 'o  .rootlogon.py finished. ' 


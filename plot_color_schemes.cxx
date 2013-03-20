{
   TCanvas * c = 0;
   Int_t col = 0;

   col=3000;
   c = draw_colors(col);
   c->SaveAs(Form("plots/color_scheme%d.png",col));
   c->SaveAs(Form("plots/color_scheme%d.svg",col));

   col=4000;
   c = draw_colors(col);
   c->SaveAs(Form("plots/color_scheme%d.png",col));
   c->SaveAs(Form("plots/color_scheme%d.pdf",col));
   c->SaveAs(Form("plots/color_scheme%d.svg",col));

   col=4500;
   c = draw_colors(col);
   c->SaveAs(Form("plots/color_scheme%d.png",col));
   c->SaveAs(Form("plots/color_scheme%d.pdf",col));
   c->SaveAs(Form("plots/color_scheme%d.svg",col));


   //set_color_scheme(30,255,0,0,col=5000);
   col=5000;
   c = draw_colors(col);
   c->SaveAs(Form("plots/color_scheme%d.png",col));
   c->SaveAs(Form("plots/color_scheme%d.svg",col));

   //set_color_scheme(45,55,0,100,col=6000);
   col=6000;
   c = draw_colors(col);
   c->SaveAs(Form("plots/color_scheme%d.png",col));
   c->SaveAs(Form("plots/color_scheme%d.svg",col));

   //set_color_scheme(30,5,50,150,col=7000);
   col=7000;
   c = draw_colors(col);
   c->SaveAs(Form("plots/color_scheme%d.png",col));
   c->SaveAs(Form("plots/color_scheme%d.svg",col));

   //set_color_scheme(60,0,30,50,col=8000);
   col=8000;
   c = draw_colors(col);
   c->SaveAs(Form("plots/color_scheme%d.png",col));
   c->SaveAs(Form("plots/color_scheme%d.svg",col));

   //set_color_scheme(30,40,30,50,col=9000);
   col=9000;
   c = draw_colors(col);
   c->SaveAs(Form("plots/color_scheme%d.png",col));
   c->SaveAs(Form("plots/color_scheme%d.svg",col));

   //set_color_scheme(23,100,50,0,col=10000);
   col=10000;
   c = draw_colors(col);
   c->SaveAs(Form("plots/color_scheme%d.png",col));
   c->SaveAs(Form("plots/color_scheme%d.svg",col));

}


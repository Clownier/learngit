kkkkkkkkkkkkkkk

#include <stdio.h>
#include <stdlib.h>
#define LINE 1024k



bool AllisNum(string str)
   {
       for (int i = 0; i < str.size(); i++)
         {
               int tmp = (int)str[i];
	       //std::cout<<"kkkkkkk=="<<tmp<<std::endl;
               if ((tmp >= 48 && tmp <= 57)||tmp==10 || tmp==13)
                {
	              continue;
	           }
              else
                {
	              return false;
	          }
         }
      return true;
  }




int min_f;
int max_f;
int number(void)
{
  printf("enter the max_f and min_f:\n");
  scanf("%d%d",&max_f,&min_f);
  return max_f-min_f+1;
}
int n_0;
int s_0;
static int num_f;
//int n_0=2382;////////081127       ////////18kev_12um
//int n_0=2376;////////081129_1     ////////16kev_12um
//int n_0=2416;////////081129_2      ////////18kev_12um
//int n_0=2438;////////081130      ////////14kev_12um
//int n_0=2463;////////081201      ////////12kev_12um
//int n_0=2445;////////081202     ////////10kev_12um
//int n_0=2474;////////081203    ////////8kev_12um
//int n_0=2391;////////081204    ////////18kev_7um
//int n_0=2404;////////081206     ////////16kev_7um
//int n_0=2415;////////081207    ////////14kev_7um
//int n_0=2412;////////081209     ////////12kev_7um
//int n_0=2420;////////081210       ////////10kev_7um
//int n_0=2402;////////081211   ////////8kev_7um
void choose(void)
{
  int kev,um;
  printf("enter the kev and um:\n");
  scanf("%d%d",&kev,&um);
  printf("kev=%d,um=%d\n",kev,um );
  printf("num_f=%d\n",num_f );
  if(um==12)
    {
      switch(kev)
	{
        case 18:n_0=2382;
                s_0=1127;
                break;
        //case 18:n_0=2416;
                s_0=1129;
                break;
       	case 16:n_0=2376;
                s_0=1129;
                break;
      	case 14:n_0=2438;
                s_0=1130;
                break;
      	case 12:n_0=2463;
                s_0=1201;
                break;
      	case 10:n_0=2445;
                s_0=1202;
                break;
      	case 8:n_0=2474;
                s_0=1203;
                break;
        }
    }
  else if(um==7)
    {
      switch(kev)
          	{
          	case 18:n_0=2391;
                    s_0=1204;
                    break;
            case 16:n_0=2404;
                    s_0=1206;
                    break;
            case 14:n_0=2415;
                    s_0=1207;
                    break;
            case 12:n_0=2412;
                    s_0=1209;
                    break;
            case 10:n_0=2420;
                    s_0=1210;
                    break;
            case 8:n_0=2402;
                    s_0=1211;
                    break;
            }
     }
     printf("n_0=%d,s_0=%d\n",n_0,s_0 );
}
void draw(){
  gStyle->SetOptStat(0);
  //gStyle->SetTextFont(2);

  //////////
  num_f=number();
  TH1F *hh[1024];
  TCanvas *cc[1024];
    for(int n=0;n<num_f;n++){
      int mm=n+min_f;
      TString his_name=Form("test%d_his",mm);
      TString can_name=Form("test%d_can",mm);


      cc[n] = new TCanvas( can_name,can_name, 600, 600 );
      //      hh[n] = new TH1F(his_name,his_name,512,-10.,10.);
      //      hh[n] = new TH1F(his_name,his_name,256,-4.,4.0);

      if(n%2==0){
	hh[n] = new TH1F(his_name,his_name,512,-10.,10.);
	//     hh[n] = new TH1F(his_name,his_name,256,-4.,4.5);
      }else{
	hh[n] = new TH1F(his_name,his_name,512,-10.,10.);
        //  hh[n] = new TH1F(his_name,his_name,256,-4.,4.0);


      }


  }





  ////////////
  FILE *fp;
  //char *buf, filename[20], *p;
  char  *p;
  char *buf[1024] = {0};
  char b[50];
  double max=-111111;
  int test_num;
  double an;
  double max_an;
  //  double run_time;
  std::vector<double>run_time;
  choose();
  printf("%d\n",s_0 );
  for(int n=min_f;n<=max_f;n++){ /////file

    //    if(n%2!=0)continue;//////  remain even test

    an=(n-2.)/2*0.2;
    //if(n%2==0)continue;/////// remaim odd test
    char s[255];
    sprintf( s,"../neg/08%d/test%d.mp",s_0, n);
    printf("%s\n",s );

  //filename="./081127/test4.mp";
  if ((fp=fopen(s, "r"))==NULL) {
    printf("open file error!!%s\n",s);
    return;
  }

  buf=(char*)malloc(LINE*sizeof(char));
  //gets(buf);
  double tt=-1.;
  double con=-1000.;

  int n_i=0;
  while(1) {
    char b[50];
    int cnt_index=0,cnt_int=0;
    p=fgets(buf, LINE, fp);
    if(!p)
      break;

    string s1(p);
    string s2;
    string s3;
    string time;
    string num;

    //std::cout<<"size="<<s1.size()<<std::endl;

         /*
    string time("livetime");
    string::size_type found_1 = s1.find(time);
    if (found_1!=string::npos){
      std::cout<<"kkkkkkkkkkkkkk"<<std::endl;
    }
    */
    //std::cout<<p<<std::endl;
    s2.assign( s1, 0, 8 );
    if(s2=="livetime"){
      //std::cout<<"kkkkkkkkkkkkkk"<<std::endl;
      time.assign( s1, 9, 30 );
      tt=atof(time.c_str());
      //run_time=tt;
      run_time.push_back(tt);
      //std::cout<<tt<<std::endl;
    }

    //s2.assign( s1, 0, 8 );
    if(s2=="TOTALSUM"){
      //std::cout<<"mmmmmmmmmmmmm"<<std::endl;
      num.assign( s1, 9, 30 );
      con=atof(num.c_str());
      //std::cout<<con<<std::endl;
    }
    //std::cout<<con<<"   "<<tt<<"   "<<con/tt<<std::endl;

    if(tt>0 && con>0){
      if((con/tt)>max){max=con/tt;
	test_num=n;
	max_an=an;
      }
      //      std::cout<<"test"<<n<<"  "<<an<<"  "<<con<<"   "<<tt<<"   "<<con/tt<<"   "<<max<<std::endl;
      // break;
    }

    int count;

    if(AllisNum(s1)){
      s3.assign( s1, 0, s1.size()-2);
      count=atof(s1.c_str());
      //std::cout<<"counts_ok="<<s3<<std::endl;
      //  std::cout<<"n_i="<<n_i<<"   "<<"counts_ok="<<count<<std::endl;
      n_i=n_i+1;
    }
    //std::cout<<"counts="<<s1<<std::endl;
    //std::cout<<"ppppppp"<<std::endl;
    //std::cout<<s2<<std::endl;

    double theta;
    //int n_0=2000;

    theta=TMath::ATan((n_i-n_0)*0.0018/23.0)*180./3.1415926.;
    //std::cout<<"n_i="<<n_i<<"   "<<"counts_ok="<<count<<"  "<<theta<<std::endl;
  //std::cout<<n_i<<"   "<<n_0<<std::endl;
  ///////fill
  if(count!=0){
    for(int ii=0;ii<count;ii++){
      //std::cout<<(n-min_f)<<std::endl;
      int tm_num=n-min_f;
      hh[tm_num]->Fill(theta);
    }

  }
  /////////fill
  }//////while




  }////////file

for(int kk=0;kk<num_f;kk++){
    cc[kk]->cd();
    cc[kk]->SetLeftMargin(0.15);
    cc[kk]->SetBottomMargin(0.15);
    Double_t norm = hh[kk]->GetEntries();
    std::cout<<norm<<"   "<<run_time[kk]<<"   "<<norm/run_time[kk]<<std::endl;
    //hh[kk]->Scale(1/norm);
    hh[kk]->Scale(1/run_time[kk]);
     hh[kk]->GetXaxis()->SetTitle("Observing angle(Deg)");
     hh[kk]->GetXaxis()->CenterTitle();
     hh[kk]->GetYaxis()->SetTitle("Intensity");
    hh[kk]->GetYaxis()->CenterTitle();
    hh[kk]->GetYaxis()->SetTitleFont(22);
    hh[kk]->GetXaxis()->SetTitleFont(22);
    hh[kk]->GetYaxis()->SetLabelFont(22);
    hh[kk]->GetXaxis()->SetLabelFont(22);
    hh[kk]->GetYaxis()->SetNdivisions(4);
    hh[kk]->GetXaxis()->SetNdivisions(4);
     hh[kk]->GetXaxis()->SetTitleSize(0.05);
     hh[kk]->GetXaxis()->SetLabelSize(0.04);
    //  h->GetYaxis()->SetLabelSize(0.05);
     hh[kk]->GetYaxis()->SetTitleSize(0.05);
     hh[kk]->GetYaxis()->SetTitleOffset(1.2);
     hh[kk]->GetYaxis()->SetLabelSize(0.04);

     hh[kk]->SetLineColor(kBlack);
     hh[kk]->SetTitle("");
    hh[kk]->Draw();
    //c1->Print(pdfname);
#if 0

    //int mm=n+min_f;
    //String his_name=Form("test%d_his",mm);
    cc[kk]->Modified(); cc[kk]->Update();


    cc[kk]->Print(Form("12um_18kev_%d_can.png",kk));


#endif

  }


}////////main

#include "ViennaTool/interface/FFCalculator.h"

#include <iostream>
#include <sstream>

using namespace std;

FFCalculator::FFCalculator(//Int_t N_p_Wjets,Int_t N_p_DY,Int_t N_p_TT,Int_t N_p_QCD, Int_t N_p_QCD_AI,
                           Int_t N_p_Wjets,Int_t N_p_DY,Int_t N_p_TT_SR,Int_t N_p_TT_CR,Int_t N_p_QCD, Int_t N_p_QCD_AI,
                           Int_t N_eta_Wjets,Int_t N_eta_DY,Int_t N_eta_TT,Int_t N_eta_QCD,
                           Int_t N_t_Wjets,Int_t N_t_DY,Int_t N_t_TT,Int_t N_t_QCD,
                           Int_t N_m_Wjets,Int_t N_m_DY,Int_t N_m_TT,Int_t N_m_QCD,
                           //Int_t N_j_Wjets,Int_t N_j_DY,Int_t N_j_TT,Int_t N_j_QCD,
                           Int_t N_j_Wjets,Int_t N_j_DY,Int_t N_j_TT_SR,Int_t N_j_TT_CR,Int_t N_j_QCD,
                           const Double_t Pt_cuts_Wjets[],const Double_t Pt_cuts_DY[],const Double_t Pt_cuts_TT_SR[],const Double_t Pt_cuts_TT_CR[],const Double_t Pt_cuts_QCD[],const Double_t Pt_cuts_QCD_AI[],
                           const Double_t Eta_cuts_Wjets[],const Double_t Eta_cuts_DY[],const Double_t Eta_cuts_TT[],const Double_t Eta_cuts_QCD[],
                           const Int_t Decay_cuts_Wjets[],const Int_t Decay_cuts_DY[],const Int_t Decay_cuts_TT[],const Int_t Decay_cuts_QCD[],
                           const Double_t Mt_cuts_Wjets[],const Double_t Mt_cuts_DY[],const Double_t Mt_cuts_TT[],const Double_t Mt_cuts_QCD[],
                           const Int_t Njet_cuts_Wjets[],const Int_t Njet_cuts_DY[],const Int_t Njet_cuts_TT_SR[],const Int_t Njet_cuts_TT_CR[],const Int_t Njet_cuts_QCD[])
{
  if (DEBUG) cout<<"Analyzer created."<<std::endl;
  //Initialise constants
  n_p_Wjets=N_p_Wjets;
  pt_cuts_Wjets=(Double_t*)malloc(n_p_Wjets*sizeof(Double_t));
  for(Int_t i=0;i<n_p_Wjets;i++) pt_cuts_Wjets[i]=Pt_cuts_Wjets[i];

  n_p_DY=N_p_DY;
  pt_cuts_DY=(Double_t*)malloc(n_p_DY*sizeof(Double_t));
  for(Int_t i=0;i<n_p_DY;i++) pt_cuts_DY[i]=Pt_cuts_DY[i];

  //n_p_TT=N_p_TT;
  //pt_cuts_TT=(Double_t*)malloc(n_p_TT*sizeof(Double_t));
  //for(Int_t i=0;i<n_p_TT;i++) pt_cuts_TT[i]=Pt_cuts_TT[i];

  n_p_TT_SR=N_p_TT_SR;
  pt_cuts_TT_SR=(Double_t*)malloc(n_p_TT_SR*sizeof(Double_t));
  for(Int_t i=0;i<n_p_TT_SR;i++) pt_cuts_TT_SR[i]=Pt_cuts_TT_SR[i];

  n_p_TT_CR=N_p_TT_CR;
  pt_cuts_TT_CR=(Double_t*)malloc(n_p_TT_CR*sizeof(Double_t));
  for(Int_t i=0;i<n_p_TT_CR;i++) pt_cuts_TT_CR[i]=Pt_cuts_TT_CR[i];

  n_p_QCD=N_p_QCD;
  pt_cuts_QCD=(Double_t*)malloc(n_p_QCD*sizeof(Double_t));
  for(Int_t i=0;i<n_p_QCD;i++) pt_cuts_QCD[i]=Pt_cuts_QCD[i];

  n_p_QCD_AI=N_p_QCD_AI;
  pt_cuts_QCD_AI=(Double_t*)malloc(n_p_QCD_AI*sizeof(Double_t));
  for(Int_t i=0;i<n_p_QCD_AI;i++) pt_cuts_QCD_AI[i]=Pt_cuts_QCD_AI[i];

  n_t_Wjets=N_t_Wjets;
  decay_cuts_Wjets=(Int_t*)malloc(n_t_Wjets*sizeof(Int_t));
  for(Int_t i=0;i<n_t_Wjets;i++) decay_cuts_Wjets[i]=Decay_cuts_Wjets[i];

  n_t_DY=N_t_DY;
  decay_cuts_DY=(Int_t*)malloc(n_t_DY*sizeof(Int_t));
  for(Int_t i=0;i<n_t_DY;i++) decay_cuts_DY[i]=Decay_cuts_DY[i];

  n_t_TT=N_t_TT;
  decay_cuts_TT=(Int_t*)malloc(n_t_TT*sizeof(Int_t));
  for(Int_t i=0;i<n_t_TT;i++) decay_cuts_TT[i]=Decay_cuts_TT[i];

  n_t_QCD=N_t_QCD;
  decay_cuts_QCD=(Int_t*)malloc(n_t_QCD*sizeof(Int_t));
  for(Int_t i=0;i<n_t_QCD;i++) decay_cuts_QCD[i]=Decay_cuts_QCD[i];


  n_e_Wjets=N_e_Wjets;
  eta_cuts_Wjets=(Double_t*)malloc(n_e_Wjets*sizeof(Double_t));
  for(Int_t i=0;i<n_e_Wjets;i++) eta_cuts_Wjets[i]=Eta_cuts_Wjets[i];

  n_e_DY=N_e_DY;
  eta_cuts_DY=(Double_t*)malloc(n_e_DY*sizeof(Double_t));
  for(Int_t i=0;i<n_e_DY;i++) eta_cuts_DY[i]=Eta_cuts_DY[i];

  n_e_TT=N_e_TT;
  eta_cuts_TT=(Double_t*)malloc(n_e_TT*sizeof(Double_t));
  for(Int_t i=0;i<n_e_TT;i++) eta_cuts_TT[i]=Eta_cuts_TT[i];

  n_e_QCD=N_e_QCD;
  eta_cuts_QCD=(Double_t*)malloc(n_e_QCD*sizeof(Double_t));
  for(Int_t i=0;i<n_e_QCD;i++) eta_cuts_QCD[i]=Eta_cuts_QCD[i];


  n_m_Wjets=N_m_Wjets;
  mt_cuts_Wjets=(Double_t*)malloc(n_m_Wjets*sizeof(Double_t));
  for(Int_t i=0;i<n_m_Wjets;i++) mt_cuts_Wjets[i]=Mt_cuts_Wjets[i];

  n_m_DY=N_m_DY;
  mt_cuts_DY=(Double_t*)malloc(n_m_DY*sizeof(Double_t));
  for(Int_t i=0;i<n_m_DY;i++) mt_cuts_DY[i]=Mt_cuts_DY[i];

  n_m_TT=N_m_TT;
  mt_cuts_TT=(Double_t*)malloc(n_m_TT*sizeof(Double_t));
  for(Int_t i=0;i<n_m_TT;i++) mt_cuts_TT[i]=Mt_cuts_TT[i];

  n_m_QCD=N_m_QCD;
  mt_cuts_QCD=(Double_t*)malloc(n_m_QCD*sizeof(Double_t));
  for(Int_t i=0;i<n_m_QCD;i++) mt_cuts_QCD[i]=Mt_cuts_QCD[i];


  n_j_Wjets=N_j_Wjets;
  njet_cuts_Wjets=(Int_t*)malloc(n_j_Wjets*sizeof(Double_t));
  for(Int_t i=0;i<n_j_Wjets;i++) njet_cuts_Wjets[i]=Njet_cuts_Wjets[i];

  n_j_DY=N_j_DY;
  njet_cuts_DY=(Int_t*)malloc(n_j_DY*sizeof(Double_t));
  for(Int_t i=0;i<n_j_DY;i++) njet_cuts_DY[i]=Njet_cuts_DY[i];

  //n_j_TT=N_j_TT;
  //njet_cuts_TT=(Int_t*)malloc(n_j_TT*sizeof(Double_t));
  //for(Int_t i=0;i<n_j_TT;i++) njet_cuts_TT[i]=Njet_cuts_TT[i];

  n_j_TT_SR=N_j_TT_SR;
  njet_cuts_TT_SR=(Int_t*)malloc(n_j_TT_SR*sizeof(Double_t));
  for(Int_t i=0;i<n_j_TT_SR;i++) njet_cuts_TT_SR[i]=Njet_cuts_TT_SR[i];

  n_j_TT_CR=N_j_TT_CR;
  njet_cuts_TT_CR=(Int_t*)malloc(n_j_TT_CR*sizeof(Double_t));
  for(Int_t i=0;i<n_j_TT_CR;i++) njet_cuts_TT_CR[i]=Njet_cuts_TT_CR[i];

  n_j_QCD=N_j_QCD;
  njet_cuts_QCD=(Int_t*)malloc(n_j_QCD*sizeof(Double_t));
  for(Int_t i=0;i<n_j_QCD;i++) njet_cuts_QCD[i]=Njet_cuts_QCD[i];

  for (int i=0; i<NB_MTCORR; i++){
    corr_d[i]=-999; corr_k[i]=-999;
  }

  TH1::SetDefaultSumw2(kTRUE);
}

FFCalculator::~FFCalculator()
{
}

void FFCalculator::calcFFweights(const TString data_file, const std::vector<TString> weight_files, const std::vector<TString> presel_files, const TString m_path_img, const TString m_path_w, const TString tf_name, Int_t mode)
{
  std::cout << "In calcFFweights" << std::endl;

  TString s_ctr[]={"1","2","3","4","5","6","7","8","9","10","11","12"};

  std::vector<TString> fnames(presel_files);
  fnames.push_back(data_file);

  std::vector<TString> wnames(weight_files);
  wnames.push_back(data_file);

  unsigned PS_SIZE=presel_files.size();

  std::vector<TH1D*> h_n; h_n.resize(PS_SIZE+1); //+1 is data
  std::vector<TH1D*> h_n_tt; h_n_tt.resize(PS_SIZE+1);
  std::vector<TH1D*> h_n_tight; h_n_tight.resize(PS_SIZE+1);

  std::vector<TH1D*> h_w; h_w.resize(PS_SIZE+1); //+1 is QCD
  std::vector<TH1D*> h_w_tight; h_w_tight.resize(PS_SIZE+1);

  TString hss_string = "h_ss_n"; TString h_qcd_rest_n = "h_qcd_rest";
  if(!inclusive_selection){
    for(Int_t icat=0; icat<nCAT; icat++){
      if(catMode[icat] & mode) {hss_string = hss_string + categories[icat];}
      if(catMode[icat] & mode) {h_qcd_rest_n = h_qcd_rest_n + categories[icat];}
    }
  }
  TH1D* h_ss=new TH1D( hss_string,"",nbins_weight,min_weight,max_weight  );
  TH1D* h_qcd_rest=new TH1D( h_qcd_rest_n,"",nbins_weight,min_weight,max_weight  );  

  for (unsigned i=0; i<=PS_SIZE; i++){
    loadFile(fnames.at(i),"Events");
    h_n.at(i)      =new TH1D("h_n_"      +s_ctr[i],"",nbins_weight,min_weight,max_weight);
    h_n_tt.at(i)      =new TH1D("h_n_tt"      +s_ctr[i],"",nbins_weight,min_weight,max_weight);
    h_n_tight.at(i)=new TH1D("h_n_tight_"+s_ctr[i],"",nbins_weight,min_weight,max_weight);
    Int_t nentries=Int_t(event_s->fChain->GetEntries());
    std::cout<< "Processing " << fnames.at(i) << " with \t" << nentries << " events."<<std::endl;
    for(Int_t jentry=0;jentry<nentries;jentry++) {
      event_s->GetEntry(jentry);
      Double_t fracWeight=event_s->weight_sf;
      if ( !fulfillCategory(mode) ) continue;
      if ( this->isInSR(NO_SR) ){
	if (this->isLoose()) h_n.at(i)->Fill(this->getWeightBin(),fracWeight);
	else if (this->isTight()) h_n_tight.at(i)->Fill(this->getWeightBin(),fracWeight);
        if (this->isTight_alt()) h_n_tt.at(i)->Fill(this->getWeightBin(),fracWeight);
      }
      if ( this->isInSR( NO_SR | _SS ) && this->isLoose() ) 
        h_ss->Fill(this->getWeightBin(),fracWeight *(-2*(i<PS_SIZE)+1)    ); //-1 for MC, +1 for data
      if ( CHAN==kTAU && this->isInSR( NO_SR ) && this->isLoose() ) 
        h_qcd_rest->Fill(this->getWeightBin(),fracWeight *(-2*(i<PS_SIZE)+1)    ); //-1 for MC, +1 for data
      else if( CHAN!=kTAU && this->isInSR( NO_SR ) && this->isLoose() ) 
        h_qcd_rest->Fill(this->getWeightBin(),fracWeight *(-2*(i<PS_SIZE)+1)    ); //-1 for MC, +1 for data
    }
    cout << "Name: " << fnames.at(i) << " " << h_ss->Integral() << endl;
    cout << "Name: " << fnames.at(i) << " " << h_qcd_rest->Integral() << endl;
  }

  if (tf_name!=""){            //do weights from template fit

    std::vector<TH1D*> templates(h_n);
    std::vector<TH1D*> templates_tt(h_n_tt);

    TString CF = COINFLIP==1 ? "" : "_DC";
    TFile *ft=new TFile(tf_name,"RECREATE");
    for (int i=(int)fnames.size()-1; i>=0; i--){
      TString stmp=fnames.at(i); cout << stmp << endl; stmp.ReplaceAll(CF+".root",""); stmp.ReplaceAll(path_presel+"preselection_",""); stmp.ReplaceAll("_woQCD",""); stmp.ReplaceAll("MCsum","data"); cout << stmp << endl;
      if(!inclusive_selection){
        for(Int_t icat=0; icat<nCAT; icat++){
          if(catMode[icat] & mode) {stmp = stmp + categories[icat];}
        }
      }
      //if(CALC_SS_SR) stmp=stmp+"_SS_SR";
      TH1D* h_template=(TH1D*)templates.at(i)->Clone("h_template_"+stmp); h_template->Write();
    }
    TString tf_name_tt = tf_name; tf_name_tt.ReplaceAll(".root","_vlooseAntiIso.root");
    TFile *ft_tt=new TFile(tf_name_tt,"RECREATE");
    for (int i=(int)fnames.size()-1; i>=0; i--){
      TString stmp=fnames.at(i); cout << stmp << endl; stmp.ReplaceAll(".root",""); stmp.ReplaceAll(path_presel+"preselection_",""); stmp.ReplaceAll("_woQCD",""); stmp.ReplaceAll("MCsum","data"); cout << stmp << endl;
      if(!inclusive_selection){
        for(Int_t icat=0; icat<nCAT; icat++){
          if(catMode[icat] & mode) {stmp = stmp + categories[icat];}
        }
      }
      TH1D* h_template_tt=(TH1D*)templates_tt.at(i)->Clone("h_template_"+stmp); h_template_tt->Write();
    }
    
    ft->cd();

    TString h_template_QCD="h_template_QCD";
    if(!inclusive_selection){
      for(Int_t icat=0; icat<nCAT; icat++) if(catMode[icat] & mode) {h_template_QCD=h_template_QCD+categories[icat];}
    }
    TH1D* h_template=(TH1D*)h_ss->Clone(h_template_QCD);
    
    //    TH1D* hqcd_OS_SS_factor;
    //    hqcd_OS_SS_factor= new TH1D("factor","",nbins_mt,hist_min_mt,hist_max_mt);
    TH1D* hqcd_OS_SS_factor=(TH1D*)h_ss->Clone("factor");
    //    for (int ib=1; ib<=nbins_mt; ib++){
    for (int ib=0; ib<=hqcd_OS_SS_factor->GetNbinsX(); ib++){
      hqcd_OS_SS_factor->SetBinContent(ib, 1.06);
      hqcd_OS_SS_factor->SetBinError(ib, 1.06/10);
    }
    h_template->Multiply( hqcd_OS_SS_factor );

    h_template->Write();

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //FIXME: Do it after checking if fit converges!
    TString h_template_QCD_rest="h_template_QCD_rest";
    if(!inclusive_selection){
      for(Int_t icat=0; icat<nCAT; icat++) if(catMode[icat] & mode) {h_template_QCD_rest=h_template_QCD_rest+categories[icat];}
    }
    TH1D* h_template_qcd=(TH1D*)h_qcd_rest->Clone(h_template_QCD_rest);
    for (int ib=0; ib<=h_qcd_rest->GetNbinsX(); ib++){
      if( h_qcd_rest->GetBinContent(ib) < 0. ) h_qcd_rest->SetBinContent(ib,0.);
    }
      
    h_template_qcd->Write();
    ft_tt->cd();
    h_template->Write();
    h_template_qcd->Write();
    ft->Close();
    ft_tt->Close();

    this->calcWeightFromFit(tf_name,m_path_img,m_path_w,"",mode);
    //if(CHAN==kTAU)this->calcWeightFromFit(tf_name_tt,m_path_img,m_path_w,"_vlooseAntiIso",mode); //might be interesting for other channels as well

  } else{     //do weights from MC, and QCD=data-rest MC


    //now to QCD: difference data to MC backgrounds (w/o QCD MC)
    TH1D* h_n_qcd       = new TH1D(*h_n.back()       ); //data
    TH1D* h_n_qcd_tight = new TH1D(*h_n_tight.back() ); //data
    for (unsigned i=0; i<PS_SIZE; i++){
      h_n_qcd->Add(       h_n.at(i)       , -1 );
      h_n_qcd_tight->Add( h_n_tight.at(i) , -1 );
    }

    cout << "Works4" << endl;

    /*
      TH1D* nMCsum=new TH1D("nMCsum","",nbins_weight,min_weight,max_weight);
      TH1D* nMCsumTight=new TH1D("nMCsumTight","",nbins_weight,min_weight,max_weight);
      
      for (unsigned i=0; i<PS_SIZE; i++){
      nMCsum->Add(h_n.at(i));
      nMCsumTight->Add(h_n_tight.at(i));
      }
    */

    if (DEBUG){
      std::cout << "Sum in looseSR:\t";
      for (unsigned i=0; i<PS_SIZE; i++) std::cout << presel_files.at(i)(13+path_presel.Length(),presel_files.at(i).Length()-5-13-path_presel.Length()) << "=" << h_n.at(i)->Integral(-1,-1) << " ";
      //    std::cout << " sum: " << nMCsum->Integral(-1,-1) << std::endl;
      std::cout << " sum: " << h_n.back()->Integral(-1,-1) << std::endl;
      
      std::cout << "1st bin in looseSR:\t";
      for (unsigned i=0; i<PS_SIZE; i++) std::cout << presel_files.at(i)(13+path_presel.Length(),presel_files.at(i).Length()-5-13-path_presel.Length()) << "=" << h_n.at(i)->GetBinContent(1) << " ";
      //    std::cout << " sum: " << nMCsum->GetBinContent(1) << std::endl;
      std::cout << " sum: " << h_n.back()->GetBinContent(1) << std::endl;
    }
    
    for (unsigned i=0; i<PS_SIZE; i++){
      h_w.at(i)      =new TH1D("h_w"                ,"",nbins_weight,min_weight,max_weight);
      h_w_tight.at(i)=new TH1D("h_w_tight"          ,"",nbins_weight,min_weight,max_weight);
      
      //    h_w.at(i)->Add(h_n.at(i));
      //    h_w.at(i)->Divide(nMCsum);
      //    h_w.at(i)->Divide(h_w.at(i), nMCsum, 1, 1, "B"); //binomial errors
      h_w.at(i)->Divide(h_n.at(i), h_n.back(), 1, 1, "B"); //binomial errors
      
      //    h_w_tight.at(i)->Add(h_n_tight.at(i));
      //    h_w_tight.at(i)->Divide(nMCsumTight);
      //    h_w_tight.at(i)->Divide(h_w_tight.at(i), nMCsumTight, 1, 1, "B"); //binomial errors
      h_w_tight.at(i)->Divide(h_n_tight.at(i), h_n_tight.back(), 1, 1, "B"); //binomial errors
    }
    
    TH1D *htmp       = new TH1D("h_w"                ,"",nbins_weight,min_weight,max_weight);
    TH1D *htmp_tight = new TH1D("h_w_tight"          ,"",nbins_weight,min_weight,max_weight);
    
    htmp->Divide(h_n_qcd, h_n.back(), 1, 1, "B"); //binomial errors
    htmp_tight->Divide(h_n_qcd_tight, h_n_tight.back(), 1, 1, "B");
    
    h_w.insert(h_w.begin()+weight_files.size()-1,htmp);
    h_w_tight.insert(h_w_tight.begin()+weight_files.size(),htmp_tight);
    
    std::cout << "weight in looseSR, 1st bin:\t";
    for (unsigned i=0; i<PS_SIZE; i++) std::cout << presel_files.at(i)(13+path_presel.Length(),presel_files.at(i).Length()-5-13-path_presel.Length()) << "=" << h_w.at(i)->GetBinContent(1) << " ";
    std::cout << "QCD=" << h_w.back() << std::endl;
  
    for (unsigned i=0; i<weight_files.size(); i++){
      TFile f(weight_files.at(i),"recreate");
      h_w.at(i)->Write();
      f.Close();
    }
  
    THStack* hs = new THStack("w","");
    THStack* hsTight = new THStack("w","");
    const int *m_smap;
    if (DOQCD) m_smap=smap; else m_smap=smap_noqcd;
    for (unsigned i=0; i<PS_SIZE+1; i++){
      h_w.at(m_smap[i])->SetFillColor(vcolor[i]);
      h_w_tight.at(m_smap[i])->SetFillColor(vcolor[i]);
      hs->Add(h_w.at(m_smap[i]),"hist"); //sample mapping to "usual" order
      hsTight->Add(h_w_tight.at(m_smap[i]),"hist");
    }
    
    TCanvas* c1 = new TCanvas("c1","c_weights",1200,800);
    hs->Draw();
    gPad->SaveAs(m_path_img+"weights.png");
    c1->Close();
    
    c1 = new TCanvas("c1","weights_tight",1200,800);
    hsTight->Draw();
    gPad->SaveAs(m_path_img+"weights_tight.png");
    c1->Close();
    
  }

  for (unsigned i=0; i<PS_SIZE+1; i++){
    delete h_w.at(i);
    delete h_w_tight.at(i);
    delete h_n.at(i);
    delete h_n_tt.at(i);
    delete h_n_tight.at(i);
  }

} //end of calcFFweights

//can also be called from external
void FFCalculator::calcWeightFromFit(const TString fname, const TString m_path_img, const TString m_path_w, const TString isolation, Int_t mode){

  TString m_data="h_template_data";
  if(!DOQCD) m_data="h_template_woQCDdata";

  std::vector<TString> m_fix;
  m_fix.push_back("h_template_TT_L"); m_fix.push_back("h_template_TT_T"); m_fix.push_back("h_template_DY_L"); m_fix.push_back("h_template_DY_TT");
  if(useVV) {m_fix.push_back("h_template_VV_L"); m_fix.push_back("h_template_VV_T");}
  const int NFIX=m_fix.size();
  if(!inclusive_selection){
    for(Int_t icat=0; icat<nCAT; icat++){
      for(Int_t ifix=0;ifix<NFIX;ifix++) if(catMode[icat] & mode) {m_fix.at(ifix)=m_fix.at(ifix)+categories[icat];}
    }
  }
  const int NFIT=2;
  TString m_fit[NFIT]={ "h_template_Wjets", "h_template_QCD" };
  if(!inclusive_selection){
    for(Int_t icat=0; icat<nCAT; icat++){
      for(Int_t ifit=0;ifit<NFIT;ifit++) if(catMode[icat] & mode) {m_fit[ifit]=m_fit[ifit]+categories[icat];}
    }
  }
  const int NSUM=2;
  TString m_sum[NSUM]={ "h_template_DY_J", "h_template_TT_J" };
  if(!inclusive_selection){
    for(Int_t icat=0; icat<nCAT; icat++){
      for(Int_t isum=0;isum<NSUM;isum++) if(catMode[icat] & mode) {m_sum[isum]=m_sum[isum]+categories[icat];}
    }
  }
  const Int_t NW=NFIT+NSUM+1;
  TString m_used[NW];
  for (int i=0; i<NFIT; i++) m_used[i]=m_fit[i];
  for (int i=0; i<NSUM; i++) m_used[NFIT+i]=m_sum[i];
  m_used[NFIT+NSUM]="rest";

  Int_t m_color[NW];
  TString m_type[NW];
  for (int j=0; j<NW; j++){
    if      ( m_used[j].Contains("Wjets") ){ m_color[j]=color_Wjets; m_type[j]="Wjets"; }
    else if ( m_used[j].Contains("QCD") ){   m_color[j]=color_QCD;   m_type[j]="QCD";}
    else if ( m_used[j].Contains("TT_J") ){  m_color[j]=color_TT_J;  m_type[j]="TT_J";}
    else if ( m_used[j].Contains("DY_J") ){  m_color[j]=color_DY_J;  m_type[j]="DY_J";}
    else if ( m_used[j].Contains("rest") ){  m_color[j]=color_sum;   m_type[j]="rest";}
    else m_color[j]=kBlack;
  }
  //  const int fractions[NFIT+(NSUM>0)]={ _W_JETS , _QCD , _DY_J | _TT_J };

  /*
  const int NFIX=5;
  const TString m_fix[NFIX]={ "h_template_TT_L", "h_template_TT_T", "h_template_DY_L", "h_template_TT_J", "h_template_DY_J" };
  const int NFIT=3;
  const TString m_fit[NFIT]={ "h_template_Wjets", "h_template_QCD", "h_template_DY_TT" };
  */

  /*
  const int NFIX=6;
  const TString m_fix[NFIX]={ "h_template_TT_L", "h_template_TT_T", "h_template_DY_L", "h_template_DY_TT", "h_template_TT_J", "h_template_DY_J" };
  const int NFIT=2;
  const TString m_fit[NFIT]={ "h_template_Wjets", "h_template_QCD" };
  */

  std::vector<TH1D*> h_templates;

  TFile f(fname);

  TH1D *htmp;

  TString m_data_tmp = m_data;
  if(!inclusive_selection){
    for(Int_t icat=0; icat<nCAT; icat++){
      if(catMode[icat] & mode) {m_data_tmp = m_data_tmp + categories[icat];}
    }
  }
  htmp=(TH1D*) f.Get(m_data_tmp);
      
  TH1D *h_data=(TH1D*) htmp->Clone();
  TH1D *h_rest=new TH1D();
  TH1D *h_sum=new TH1D();

  //sum up the fixed components, and subtract from data
  for (int i=0; i<NFIX; i++){
    htmp=(TH1D*) f.Get(m_fix.at(i));
    if (i==0) h_rest=(TH1D*) htmp->Clone();
    else h_rest->Add(htmp);
  }
  h_data->Add(h_rest,-1);
  //collect the templates for the fit
  for (int i=0; i<NFIT; i++){
    if ( !DOQCD && m_fit[i].Contains("_QCD") ) continue; //FIX ME -- continue from here
    htmp=(TH1D*) f.Get(m_fit[i]);
    //    if (i==1) htmp->Scale(3); //test...
    h_templates.push_back(htmp);
  }
  //add one more template: sum of all remaining processes
  int NBINS=0;
  for (int i=0; i<NSUM; i++){
    htmp=(TH1D*) f.Get(m_sum[i]);
    if (i==0){ 
      NBINS=htmp->GetNbinsX();
      h_sum=(TH1D*) htmp->Clone();
    }
    else{ 
      h_sum->Add( htmp );
    }
  }
  if (NSUM>0) h_templates.push_back(h_sum);
  
  TH1D *h_sum_frac[NSUM];
  for (int i=0; i<NSUM; i++){
    htmp=(TH1D*) f.Get(m_sum[i]);
    h_sum_frac[i]=new TH1D( *h_sum );
    h_sum_frac[i]->Divide( htmp, h_sum, 1,1,"B" );
  }

  //get fractions before fit
  if (DEBUG && h_templates.size()>0 ){
    //as used in the fit:
    double n_templates_all=0;
    for (unsigned it=0; it<h_templates.size(); it++){
      n_templates_all+=h_templates.at(it)->Integral();
    }
    std::cout << "As in templates: Pre-fit  fraction" << std::endl;
    for (unsigned it=0; it<h_templates.size(); it++){
      std::cout << "Pre-fit  fraction:\t" << h_templates.at(it)->Integral()/n_templates_all << std::endl;
    }
    //all (split, plus sum of true bkg):
    std::cout << std::endl << "All components: Pre-fit  fraction" << std::endl;
    double n_all=n_templates_all+h_rest->Integral();

    for (int it=0; it<NFIT; it++){
      std::cout << "Pre-fit  fraction:\t" << h_templates.at(it)->Integral()/n_all << "\t" << m_type[it] << std::endl;
    }
    for (int it=0; it<NSUM; it++){
      TH1D *h_d_tmp=(TH1D*)h_sum->Clone(); h_d_tmp->Multiply(h_sum_frac[it]);
      std::cout << "Pre-fit  fraction:\t" << h_d_tmp->Integral()/n_all << "\t" << m_type[NFIT+it] << std::endl;
    }
    std::cout << "Pre-fit  fraction:\t" << h_rest->Integral()/n_all << "\t" << m_type[NFIT+NSUM] << std::endl;   
    
  }

  std::vector<TH1D*> res;
  TH1D* res_data=new TH1D();
  std::vector<TH1D*> h_w;
  Int_t fit_result=this->doTemplateFit(h_data, h_templates, m_path_img, res, res_data, mode);
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////// This is a first version how to intercept categories in which the fit doesn't converge, histograms for QCD and the "rest" still need to be added
  if( !doFit || fit_result!=0 || CHAN==kTAU || !inclusive_selection ){
    std::vector<TH1D*> h_check; //if fit doesn't converge, this vector contains all the necessary histograms
    TH1D* htmp_check;
    for (int i=0; i<NFIT; i++){
      if ( !DOQCD && m_fit[i].Contains("_QCD") ){
        htmp_check=(TH1D*) f.Get( m_fit[i] );
        for(int i=1;i<=htmp_check->GetNbinsX();i++) htmp_check->SetBinContent(i,0);
      }
      else if (m_fit[i].Contains("_QCD")){
        TString qcd_rest=m_fit[i];
        qcd_rest.ReplaceAll("_QCD","_QCD_rest");
        htmp_check=(TH1D*) f.Get(qcd_rest);
        for(int i=1;i<=htmp_check->GetNbinsX();i++){ if(htmp_check->GetBinContent(i)<0) htmp_check->SetBinContent(i,0);}
      } 
      else htmp_check=(TH1D*) f.Get(m_fit[i]);
      for(int i=1;i<=htmp_check->GetNbinsX();i++){ if(htmp_check->GetBinContent(i)<0) htmp_check->SetBinContent(i,0);}
      h_check.push_back(htmp_check);
    }
    for (int i=0; i<NSUM; i++){
      htmp_check=(TH1D*) f.Get(m_sum[i]);
      h_check.push_back(htmp_check);
      for(int i=1;i<=htmp_check->GetNbinsX();i++){ if(htmp_check->GetBinContent(i)<0) htmp_check->SetBinContent(i,0);}
    }
    //h_check.push_back(h_rest);
    TH1D *h_all;
    for(int iall=0;iall<h_check.size();iall++){
      if (iall==0) h_all=(TH1D*) h_check.at(0)->Clone();
      else h_all->Add(h_check.at(iall));
    }
    for(int i=0;i<h_check.size();i++){
      h_check.at(i)->Divide(h_all);
    }
    
    for(Int_t j=0;j<h_check.size();j++){
      TH1D *htmp = new TH1D("h_w"+sNum[j],"",nbins_weight,min_weight,max_weight);
      for(Int_t ibins=0; ibins<=NBINS; ibins++){ //ibins<h_templates.at(j)->GetNbinsX()
        if(h_check.at(j)->GetBinContent(ibins)>0) {htmp->SetBinContent( ibins, h_check.at(j)->GetBinContent(ibins) );}
        if(h_check.at(j)->GetBinContent(ibins)>0) {htmp->SetBinError( ibins, h_check.at(j)->GetBinError(ibins) );}
        
        else htmp->SetBinContent(ibins,0);
      }
      h_w.push_back(htmp);
    }
  }
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  else{
  
    //  std::cout << "RES " << res_data->Integral() << " " << res.size() << std::endl;

    if (!DOQCD){ //insert empty histogram to make the rest work
      int qcd_pos=-1;
      for (int i=0; i<NW; i++){
        if ( m_used[i].Contains("QCD") ) qcd_pos=i;
      }
      if ( qcd_pos>=0 ){
        TH1D* htmp;
        for (int i=0; i<NW; i++){ if (i!=qcd_pos){ htmp=(TH1D*)res.at(i)->Clone("qcdtmp"); break; } }
        htmp->Reset();
        res.insert(res.begin()+qcd_pos,htmp);
      }
    }

    unsigned NR=res.size();
  //  for (unsigned i=0; i<NR; i++) std::cout << res.at(i)->Integral();

    h_w.resize(NW);
    for (int j=0; j<NW; j++)    h_w.at(j) = new TH1D("h_w"+sNum[j] ,"",nbins_weight,min_weight,max_weight);
    //  for(int i=0; i<res_data->GetNbinsX(); i++){
    TH1D* h_normI=(TH1D*) res.at(0)->Clone();
    for (unsigned j=1; j<NR; j++) h_normI->Add( res.at(j) );

    TH1D* h_restI=new TH1D( *h_rest );
    h_restI->Divide(h_rest,res_data,1,1,"B");
    //h_normI->Add(h_restI);
    
    for (Int_t j=0; j<NFIT; j++)  h_w.at(j     )->Divide( res.at(j)    , h_normI , 1,1,"B");
    for (Int_t j=0; j<NSUM; j++){ 
      h_w.at(NFIT+j)->Divide(   res.at(NFIT)   , h_normI , 1,1,"B"); 
      h_w.at(NFIT+j)->Multiply( h_sum_frac[j] );
      //    for(int i=0; i<h_w.at(NFIT+j)->GetNbinsX(); i++) h_w.at(NFIT+j)->Scale( sum_frac[j].at(i) );
    }
    h_w.at(NFIT+NSUM)->Divide( h_restI , h_normI , 1,1,"B");

    for (int i=0; i<NW; i++){
      if (DEBUG){
        TH1D* h_d_tmp2=(TH1D*)h_normI->Clone(); h_d_tmp2->Multiply(res_data);
        TH1D* h_d_tmp=(TH1D*)h_w.at(i)->Clone(); h_d_tmp->Multiply( h_d_tmp2 );
        std::cout << "Post-fit fraction:\t" << h_d_tmp->Integral()/h_d_tmp2->Integral() << "\t" << m_type[i] << std::endl;
      }
    }

  }

  for (int i=0; i<NW-1; i++){
    if ( !DOQCD && m_type[i].Contains("QCD") ) continue;
    TString wname=m_path_w+"weight_"+m_type[i]+isolation;
    if(!inclusive_selection){
      for(Int_t icat=0; icat<nCAT; icat++) if(catMode[icat] & mode) {wname=wname+categories[icat];}
    }
    if(CALC_SS_SR) wname=wname+"_SS_SR";
    TFile f(wname+".root","recreate");
    h_w.at(i)->SetName("h_w");
    h_w.at(i)->Write();
    h_w.at(i)->SetName("h_w"+sNum[i]);
    f.Close();
  }

  THStack* hs = new THStack("w","");
  for (int i=0; i<NW-1; i++){
    if ( !DOQCD&& m_type[i].Contains("QCD") ) continue;
    h_w.at(i)->SetFillColor(m_color[i]);
    hs->Add(h_w.at(i),"hist");
    //    h_w.at(m_smap[i])->SetFillColor(vcolor[i]);
    //    hs->Add(h_w.at(m_smap[i]),"hist"); //sample mapping to "usual" order
  }

  TCanvas* c1 = new TCanvas("c1","fractions",1200,800);
  hs->Draw();
  TString fracstring=m_path_img+"frac"+isolation+".png";
  fracstring.ReplaceAll( ".png", getCatString_noSel(mode)+".png" );
  if(CALC_SS_SR) fracstring.ReplaceAll( ".png", "_SS_SR.png" );
  gPad->SaveAs(fracstring);
  if (ALLPLOTS){
    fracstring.ReplaceAll( ".png", ".pdf");
    gPad->SaveAs(fracstring);
    fracstring.ReplaceAll( ".pdf", ".eps");
    gPad->SaveAs(fracstring);
  }

  /*if(!inclusive_selection){
    for(Int_t icat=0; icat<nCAT; icat++) if(catMode[icat] & mode) {fracstring.ReplaceAll( ".png", categories[icat]+".png");}
  }
  gPad->SaveAs(fracstring);
  if (ALLPLOTS){
    fracstring=m_path_img+"frac.pdf";
    if(!inclusive_selection){
      for(Int_t icat=0; icat<nCAT; icat++) if(catMode[icat] & mode) {fracstring.ReplaceAll( ".pdf", categories[icat]+".pdf");}
    }
    gPad->SaveAs(fracstring);
    fracstring=m_path_img+"frac.eps";
    if(!inclusive_selection){
      for(Int_t icat=0; icat<nCAT; icat++) if(catMode[icat] & mode) {fracstring.ReplaceAll( ".eps", categories[icat]+".eps");}
    }
  gPad->SaveAs(fracstring);
  }*/

  //now some nicer plots
  if ( nbins_weight == w_pt_n*w_dm_n ){ //split by decay mode: only if total number of weight bins is #mt-bins*#dm-bins
    
    THStack* hs_split[w_dm_n]; for (int i=0; i<w_dm_n; i++) hs_split[i] = new THStack("w_split"+sNum[i],"");
    TLegend* leg = new TLegend(0.3,0.16,0.45,0.46);
    //    leg->SetFillColor(10);
    leg->SetShadowColor(10);
    leg->SetLineColor(10);
    
    std::vector<TH1D*> h_w_split[w_dm_n];
    for (int is=0; is<w_dm_n; is++){
      h_w_split[is].resize(NW);
      for (int j=0; j<NW-1; j++){
        if ( !DOQCD&& m_type[j].Contains("QCD") ) continue;
        h_w_split[is].at(j) = new TH1D("h_w_split"+mode+sNum[j]+sNum[is]+isolation ,"",w_pt_n,w_pt_v);
        h_w_split[is].at(j)->SetFillColor(m_color[j]);
        for (int ib=0; ib<w_pt_n; ib++){
          h_w_split[is].at(j)->SetBinContent( ib+1 , h_w.at(j)->GetBinContent(ib+1 + is*w_pt_n) );
        }
        h_w_split[is].at(j)->SetMaximum(1.0);
        hs_split[is]->Add(h_w_split[is].at(j),"hist");
        if (is==0){
          TString m_label="Multijet";
          for (int il=0; il<nSAMPLES; il++){ if ( vsuff[il]==m_type[j] ) m_label=vlabel[il]; }
          leg->AddEntry(h_w_split[is].at(j),m_label,"f");
        }
      }
      TCanvas* c1s = new TCanvas("c1s","fractions_split",1200,800);
      gStyle->SetHistTopMargin(0.);
      hs_split[is]->Draw();
      //      hs_split[is]->GetYaxis()->SetRangeUser(0.0,1.0);
      hs_split[is]->SetMaximum(1.0);
      hs_split[is]->GetXaxis()->SetTitle(labelPt);
      hs_split[is]->GetYaxis()->SetTitle("fraction");
      hs_split[is]->Draw();
      leg->Draw();
      TString fracstring=m_path_img+"frac_split"+sNum[is]+isolation+".png";
      fracstring.ReplaceAll( ".png", getCatString_noSel(mode)+".png" );
      if(CALC_SS_SR) fracstring.ReplaceAll(".png","_SS_SR.png");
      gPad->SaveAs(fracstring);
      
      if (ALLPLOTS){
        fracstring.ReplaceAll( ".png", ".pdf");
        gPad->SaveAs(fracstring);
        fracstring.ReplaceAll( ".pdf", ".eps");
        gPad->SaveAs(fracstring);
      }
      
      c1s->Close();
    }
    
  }
  
  c1->Close();
  
  delete hs;
  for (int i=0; i<NW-1; i++){
    delete h_w.at(i);
  }
  
}// end of calcWeightFromFit

Int_t FFCalculator::doTemplateFit(const TH1D *data, const std::vector<TH1D*> templates, const TString m_path_img, std::vector<TH1D*> &res, TH1D* &res_data, const Int_t mode){

  const unsigned NT=templates.size();

  TH1D *m_data=new TH1D(*data);
  //  for (int j=1; j<m_data->GetNbinsX(); j++) m_data->SetBinError(j,m_data->GetBinError(j)*5);

  THStack* hs2= new THStack("r","");
  for (unsigned i=0; i<NT; i++){
    templates.at(i)->SetFillColor(vcolor[i]);
    hs2->Add( templates.at(i),"hist" );
    //    std::cout << templates.at(i)->GetBinContent(1) << " " << templates.at(i)->GetBinContent(2) << " " << templates.at(i)->GetBinContent(3) << " " << templates.at(i)->GetBinContent(4) << " " << templates.at(i)->GetBinContent(5) << " " << templates.at(i)->GetBinContent(6) << std::endl;
  }
 
  TCanvas* cf; cf = new TCanvas("cf","fit fractions",1200,800);
  hs2->Draw();
  //  hs2->GetXaxis()->SetRangeUser(-0.5,20.5);
  m_data->SetLineWidth(3);
  m_data->SetMarkerStyle(8);
  m_data->SetMarkerSize(1.3);
  m_data->Draw("same Ep");
  /*gPad->SaveAs(m_path_img+"fraction_before_fit.png");
  if (ALLPLOTS){
    gPad->SaveAs(m_path_img+"fraction_before_fit.pdf");
    gPad->SaveAs(m_path_img+"fraction_before_fit.eps");
    //      c1->SaveAs(imagefilename+".C");                                                                                                                                                                                               
    }*/
  TString frac_before=m_path_img+"fraction_before_fit.png";
  frac_before.ReplaceAll( ".png", getCatString_noSel(mode)+".png" );
  if(CALC_SS_SR) frac_before.ReplaceAll(".png","_SS_SR.png");
  gPad->SaveAs(frac_before);
  if (ALLPLOTS){
    frac_before.ReplaceAll( ".png", ".pdf");
    gPad->SaveAs(frac_before);
    frac_before.ReplaceAll( ".pdf", ".eps");
    gPad->SaveAs(frac_before);
  }
  


  std::vector<TH1D*> c_templates(NT);
  TObjArray *m_templates = new TObjArray(NT);        // MC histograms are put in this array
  for (unsigned i=0; i<NT; i++){
    //  for (int j=1; j<templates.at(i)->GetNbinsX(); j++) templates.at(i)->SetBinError(j,templates.at(i)->GetBinError(j)*5);
    c_templates.at(i)=(TH1D*)templates.at(i)->Clone();
    for (int j=0; j<=c_templates.at(i)->GetNbinsX(); j++){ if (c_templates.at(i)->GetBinContent(j)<=0) c_templates.at(i)->SetBinContent(j,1e-36); } //avoid errors...
    m_templates->Add( c_templates.at(i) );
  }

  std::vector<Double_t> frac(NT);
  std::vector<Double_t> frac_err(NT);
  //  std::vector<TH1D*> res(NT);
  res.resize(NT); 
 
  TFractionFitter* fit = new TFractionFitter(m_data, m_templates,"Q"); // initialise
  //  TFractionFitter* fit = new TFractionFitter(m_data, m_templates); // initialise
  for(unsigned i=0; i<NT; i++) fit->Constrain(i,0.0,1.0);               // constrain fraction 1 to be between 0 and 1

  //  fit->SetRangeX(1,12);                    // use only the first 12 bins in the fit
  if (DEBUG) std::cout << "Excluding bins..." << std::endl;
  if (w_pt_n==25 && nbins_weight>=25){ for (int i=13; i<=25; i++) fit->ExcludeBin(i); } //exclude certaint mT bins with low stats
  if (w_pt_n==25 && nbins_weight>=50){ for (int i=38; i<=50; i++) fit->ExcludeBin(i); }
  Int_t status = fit->Fit();               // perform the fit
  std::cout << "fit status: " << status << std::endl;
  if (status == 0) {                       // check on fit status
    //    res_data = (TH1D*) fit->GetPlot();
    res_data=(TH1D*) m_data->Clone();
    //    res_data->Scale( 1/res_data->Integral() );
    THStack* hs = new THStack("r","");
    for (unsigned i=0; i<NT; i++){
      fit->GetResult( i, frac.at(i), frac_err.at(i) );
      std::cout << "Frac result: " << i << "\t" << frac.at(i) << " +/- " << frac_err.at(i) << std::endl;
      res.at(i) = (TH1D*)fit->GetMCPrediction(i);
      res.at(i)->Scale( 1/res.at(i)->Integral() * frac.at(i) );
      frac_err.at(i)/=frac.at(i); //relative unc
      for (int j=0; j<res.at(i)->GetNbinsX(); j++) res.at(i)->SetBinError( j+1 , frac_err.at(i)* res.at(i)->GetBinContent( j+1 ) );
      res.at(i)->SetFillColor(vcolor[i]);
      hs->Add( res.at(i),"hist" );
      //      std::cout << "     " << i << "\t" <<  res.at(i)->GetBinContent(1) << std::endl;
    }

    //    result->Draw("");
    //    m_data->Draw("same Ep");
    //    gPad->SaveAs(m_path_img+"result.png");

    hs->Draw();
    //    hs->GetXaxis()->SetRangeUser(-0.5,24.5);
    Double_t rd_int=res_data->Integral();
    res_data->Scale( 1/rd_int );
    res_data->SetLineWidth(3);
    res_data->SetMarkerStyle(8);
    res_data->SetMarkerSize(1.3);

    res_data->Draw("same Ep");

    TString frac_from=m_path_img+"fraction_from_fit.png";
    frac_from.ReplaceAll( ".png", getCatString_noSel(mode)+".png" );
    gPad->SaveAs(frac_from);
    if (ALLPLOTS){
      frac_from.ReplaceAll( ".png", ".pdf");
      gPad->SaveAs(frac_from);
      frac_from.ReplaceAll( ".pdf", ".eps");
      gPad->SaveAs(frac_from);
    }
    

    for (unsigned i=0; i<NT; i++) res.at(i)->Divide( res.at(i) , res_data , 1 , 1/res_data->Integral() );
    res_data->Scale( rd_int ); //return unnormalized histo
  }
  return status;

}

//calculate FF (with MC subtraction) for the case of subtracting any number of backgrounds, including none.
//FF_file is written out
void FFCalculator::calcFFCorr(const Int_t mode, const TString pre_main, const std::vector<TString> pre_sub, const TString FF_file, const TString weight_file, const Int_t cuts)
{

  std::cout << "In calcFFCorr: \t Writing " << FF_file << "\t" << flush;

  int doCR=0;
  if     ( ! (mode & SR) )  {doCR=1;} //otherwise, calculate FF in SR (for debugging)

  TH1D counter_histo_proto("c_h","Counter histogram",this->nBins(mode),-0.5,this->nBins(mode)-0.5);
  TH1D* counter_histo_loose_CR = (TH1D*) counter_histo_proto.Clone("c_l");
  TH1D* weighted_bin_center_loose= (TH1D*) counter_histo_proto.Clone("bins_weighted");
  TH1D* counter_histo_tight_alt_CR = (TH1D*) counter_histo_proto.Clone("c_t_alt");
  TH1D* counter_histo_tight_CR = (TH1D*) counter_histo_proto.Clone("c_t");
  TH1D* fakefactor_histo = (TH1D*) counter_histo_proto.Clone("c_f");
  TH1D* fakefactor_histo_alt = (TH1D*) counter_histo_proto.Clone("c_t_alt");
 
  std::vector<TH1D*> counter_histo_loose_CR_cont;
  std::vector<TH1D*> counter_histo_tight_alt_CR_cont;
  std::vector<TH1D*> counter_histo_tight_CR_cont;
  for (unsigned i=0; i<pre_sub.size(); i++){
    TString tmp; tmp+=i;
    counter_histo_loose_CR_cont.push_back( (TH1D*) counter_histo_proto.Clone("cc"+tmp+"_l")  );
    counter_histo_tight_alt_CR_cont.push_back( (TH1D*) counter_histo_proto.Clone("cc"+tmp+"_t_alt")  );
    counter_histo_tight_CR_cont.push_back( (TH1D*) counter_histo_proto.Clone("cc"+tmp+"_t")  );
  }

  TH1D* counter_histo_numer = (TH1D*) counter_histo_proto.Clone("numer");
  TH1D* counter_histo_numer_alt = (TH1D*) counter_histo_proto.Clone("numer_alt");
  TH1D* counter_histo_denom = (TH1D*) counter_histo_proto.Clone("denom");
  TH1D* counter_histo_denom_alt = (TH1D*) counter_histo_proto.Clone("denom_alt");

  int nT=0;
  int nL=0;
  int nT_alt=0;
  Double_t bin_values[this->getNjets(mode)*this->getNtracks(mode)][this->getNpts(mode)]={{0}}; Double_t bin_counters[this->getNjets(mode)*this->getNtracks(mode)][this->getNpts(mode)]={};
  loadFile(pre_main,"Events");
  //Commence loop over tree
  Int_t nentries = Int_t(event_s->fChain->GetEntries());
  unsigned ntau=1; //only consider first tau, unless MULTITAU=1
  //  std::cout <<" DOALL "<<" " " "<<" doCR "<<" " " "<<" this->isInCR(mode,i) "<<" " " "<<" this->isInSR(mode,i) "<< std::endl;
  for (Int_t jentry=0; jentry<nentries;jentry++) {
    event_s->GetEntry(jentry);
    if (MULTITAU) ntau=event_s->alltau_mt->size();
    for (unsigned i=0; i<ntau; i++){
      if ( !this->passesCuts(cuts,i) ) continue;
      //if(pre_main.Contains("data"))cout << "Before" << endl;
      if (  ( (mode & DOALL) && this->isInAll(mode,i) ) ||  ( doCR && this->isInCR(mode,i) ) || ( !doCR && this->isInSR(mode,i) )    ) {
        //if(pre_main.Contains("data"))cout << "after" << endl;
	nT=this->isTight(mode,i); nL=this->isLoose(mode,i); nT_alt=this->isTight_alt(mode,i);
	if      (nT) {counter_histo_tight_CR->Fill(this->getBin(mode,i),event_s->weight_sf);}
	if (nL) {counter_histo_loose_CR->Fill(this->getBin(mode,i),event_s->weight_sf);}
        if (nT_alt) {counter_histo_tight_alt_CR->Fill(this->getBin(mode,i),event_s->weight_sf);}

        if(nL){
          Int_t pT_index=this->getPtIndex(mode,i);
          Int_t njet_index=this->getNjetIndex(mode,i);
          Int_t dm_index=this->getTrackIndex(mode,i);
          bin_values[dm_index+this->getNtracks(mode)*njet_index][pT_index]=bin_values[dm_index+this->getNtracks(mode)*njet_index][pT_index]+event_s->alltau_pt->at(i)*event_s->weight_sf;
          bin_counters[dm_index+this->getNtracks(mode)*njet_index][pT_index]=bin_counters[dm_index+this->getNtracks(mode)*njet_index][pT_index]+event_s->weight_sf;
        }
      }
    }
  }//end loop over entries

  std::cout<<"in "<<pre_main<<": "<<counter_histo_loose_CR->Integral(-1,-1) <<" loose, "<<counter_histo_tight_CR->Integral(-1,-1)<<" tight, " <<counter_histo_tight_alt_CR->Integral(-1,-1)<<" loose tt."<<std::endl;

  for (unsigned is=0; is<pre_sub.size(); is++){
    loadFile(pre_sub.at(is),"Events");
    //Commence loop over tree
    nentries = Int_t(event_s->fChain->GetEntries());
    for (Int_t jentry=0; jentry<nentries;jentry++) {
      event_s->GetEntry(jentry);
      if (MULTITAU) ntau=event_s->alltau_mt->size();
      for (unsigned i=0; i<ntau; i++){
	if ( !this->passesCuts(cuts,i) ) continue;
	if (  ( (mode & DOALL) && this->isInAll(mode,i) ) ||  ( doCR && this->isInCR(mode,i) ) || ( !doCR && this->isInSR(mode,i) )    ) {
	  nT=this->isTight(mode,i); nL=this->isLoose(mode,i); nT_alt=this->isTight_alt(mode,i);
	  if (nT) {counter_histo_tight_CR_cont.at(is)->Fill(this->getBin(mode,i),event_s->weight_sf);}
	  else if (nL) {counter_histo_loose_CR_cont.at(is)->Fill(this->getBin(mode,i),event_s->weight_sf);}
          if (nT_alt) {counter_histo_tight_alt_CR_cont.at(is)->Fill(this->getBin(mode,i),event_s->weight_sf);}

          if(nL){
            Int_t pT_index=this->getPtIndex(mode,i);
            Int_t njet_index=this->getNjetIndex(mode,i);
            Int_t dm_index=this->getTrackIndex(mode,i);
            bin_values[dm_index+this->getNtracks(mode)*njet_index][pT_index]=bin_values[dm_index+this->getNtracks(mode)*njet_index][pT_index]+event_s->alltau_pt->at(i)*event_s->weight_sf*(-1);
            bin_counters[dm_index+this->getNtracks(mode)*njet_index][pT_index]=bin_counters[dm_index+this->getNtracks(mode)*njet_index][pT_index]+event_s->weight_sf*(-1);
          }
	}
      }
    }
    if (DEBUG) std::cout<<std::endl<<"In contamination file "<<pre_sub.at(is)<<" "<< counter_histo_loose_CR_cont.at(is)->Integral(-1,-1) <<" loose "<<counter_histo_tight_CR_cont.at(is)->Integral(-1,-1)<<" tight, " <<counter_histo_tight_alt_CR_cont.at(is)->Integral(-1,-1)<<" loose tt."<<std::endl;
  }
  
  counter_histo_numer->Add(counter_histo_tight_CR);
  counter_histo_numer_alt->Add(counter_histo_tight_alt_CR);
  counter_histo_denom->Add(counter_histo_loose_CR);
  counter_histo_denom_alt->Add(counter_histo_loose_CR);

  for (unsigned is=0; is<pre_sub.size(); is++){
    counter_histo_numer->Add(counter_histo_tight_CR_cont.at(is),-1.);
    counter_histo_numer_alt->Add(counter_histo_tight_alt_CR_cont.at(is),-1.);
    counter_histo_denom->Add(counter_histo_loose_CR_cont.at(is),-1.);
    counter_histo_denom_alt->Add(counter_histo_loose_CR_cont.at(is),-1.);
  }

  TString ff_file=FF_file; //if(calcVTightFF)ff_file.ReplaceAll(".root","_VTight.root");
  TFile f(ff_file,"RECREATE");
  f.cd();
  
  fakefactor_histo = counter_histo_numer; fakefactor_histo_alt = counter_histo_numer_alt;
  //  fakefactor_histo->Divide(counter_histo_denom); //uncorrelated errors
  fakefactor_histo->Divide(fakefactor_histo,counter_histo_denom,1,1,"B"); //binomial errors
  fakefactor_histo->SetTitle("Fakefactor");
  fakefactor_histo->SetName("c_t");
  fakefactor_histo->Write();
  fakefactor_histo_alt->Divide(fakefactor_histo_alt,counter_histo_denom_alt,1,1,"B"); //binomial errors
  fakefactor_histo_alt->SetTitle("Fakefactor");
  fakefactor_histo_alt->SetName("c_t_alt");
  fakefactor_histo_alt->Write();


  for(Int_t ijets=0;ijets<this->getNjets(mode);ijets++){
    for(Int_t idm=0;idm<this->getNtracks(mode);idm++){
      for(Int_t ipt=0;ipt<this->getNpts(mode);ipt++){
        cout << "Weighted: " << bin_values[idm+ijets*this->getNtracks(mode)][ipt] << endl;
        cout << "Counted: " << bin_counters[idm+ijets*this->getNtracks(mode)][ipt] << endl;
        cout << "Ratio: " << bin_values[idm+ijets*this->getNtracks(mode)][ipt]/bin_counters[idm+ijets*this->getNtracks(mode)][ipt] << endl;
        weighted_bin_center_loose->SetBinContent(ipt+this->getNpts(mode)*idm + (this->getNpts(mode)*this->getNtracks(mode))*ijets + 1,bin_values[idm+ijets*this->getNtracks(mode)][ipt]/bin_counters[idm+ijets*this->getNtracks(mode)][ipt] ); 
      }      
    }
  }
  weighted_bin_center_loose->Write();
                                               
                                               

                                               

  
  f.Close();

  if (DEBUG){  
    std::cout << std::endl;
    std::cout << "Value\t\tError"<<std::endl;
    for(int i=0;i<this->nBins(mode);i++) {
      std::cout << fakefactor_histo->GetBinContent(i+1)<<"\t"<<fakefactor_histo->GetBinError(i+1)<<std::endl;
    }
  }
  
  if (mode & VSVAR) return;

  TFile f_w(weight_file);
  if ( f_w.IsZombie()  ){ std::cout << "ERROR: Weight file does not exist: \"" << weight_file << "\"." << std::endl; return; }

  TH1D *weight_histo=(TH1D*)f_w.Get("h_w"); //FIXME: check sample
  //  std::cout << "ZZ " << weight_file << " " << weight_histo << std::endl;  

  TH2D *FF_weighted = new TH2D("ff_weighted","",this->nBins(mode),-0.5,-0.5+this->nBins(mode),nbins_weight,min_weight,max_weight);
  Double_t val_FF,val_weight,val,err_FF,err_weight,err;
  for(Int_t i=0;i<this->nBins(mode);i++) {//not necessary to include overflow bin here.
    for(Int_t j=0;j<=nbins_weight;j++) {//include overflow bin here!
      val_FF=fakefactor_histo->GetBinContent(i+1);
      val_weight=weight_histo->GetBinContent(j+1);
      val=val_FF*val_weight;
      FF_weighted->SetBinContent(i+1,j+1,val);
      err_FF=fakefactor_histo->GetBinError(i+1);
      err_weight=weight_histo->GetBinError(j+1);
      err=sqrt(err_FF*err_FF*val_weight*val_weight+err_weight*err_weight*val_FF*val_FF + val*val*FFW_REL_ERR*FFW_REL_ERR); //sqrt{   errFF^2 valWgt^2 + errW^2 valFF^2  }
      FF_weighted->SetBinError(i+1,j+1,err);
      //      std::cout <<val_FF<<"\t"<<val_weight<<"\t"<<val<<"\t"<<err<<std::endl;
    }
  }
  delete weight_histo;

  //calc error FF
  TH2D *FFerr[NERR];
  TRandom3 r3;
  for (int i=0; i<NERR; i++){
    //    std::cout << "calc error FF: B " << i << std::endl;
    TString hn="ff_weighted_"; if (i<10) hn+="0"; hn+=i;
    //    std::cout << "calc error FF: B " << i << " " << hn << std::endl;
    FFerr[i] = new TH2D(hn, "",this->nBins(mode),-0.5,-0.5+this->nBins(mode),nbins_weight,min_weight,max_weight);
    for (int xb=1; xb<FF_weighted->GetNbinsX(); xb++){     //FF bins
      for (int yb=1; yb<=FF_weighted->GetNbinsY(); yb++){   //weight bins
	Double_t binc=r3.Gaus( FF_weighted->GetBinContent(xb,yb) , FF_weighted->GetBinError(xb,yb)  );
	FFerr[i]->SetBinContent( xb , yb, binc );
      }
    }
  }
  
  TString FF_weighted_file=ff_file;
  FF_weighted_file.Remove(FF_weighted_file.Length()-5);
  FF_weighted_file=FF_weighted_file+"_weighted.root";
  TFile f2(FF_weighted_file,"recreate");
  FF_weighted->Write();
  for (int i=0; i<NERR; i++){ FFerr[i]->Write(); /* std::cout << "NERR " << i << "\t" << FFerr[i]->Integral() << "\t" << FF_weighted_file << std::endl; */ }
  f2.Close();
  
  if (DEBUG){
    std::cout << std::endl;
    std::cout << "Value\t\tError"<<std::endl;
    for(int i=0;i<this->nBins(mode);i++) {
      std::cout << fakefactor_histo->GetBinContent(i+1)<<"\t"<<fakefactor_histo->GetBinError(i+1)<<std::endl;
    }
    std::cout << std::endl;
    for(int i=0;i<this->nBins(mode);i++) {
      std::cout << FF_weighted->GetBinContent(i+1,1)<<"\t"<<FF_weighted->GetBinError(i+1,1)<<std::endl;
    }
  }
  
}

TH1D* FFCalculator::setCorrValue(const TString fname, const TString hname){
  TFile *fc = new TFile(fname);
  TH1D* h_corr;
  h_corr = (TH1D*) fc->Get(hname);
  cout << fname << " " << hname << " " << h_corr << endl;
  return h_corr;
}

//so far only works versus mT, and with specific bin choices
Double_t FFCalculator::getCorrValueFit(Double_t m_corr_d, Double_t m_corr_k, Int_t ind){

  for (int i=0; i<NB_MTCORR; i++){
    if ( corr_d[i]<-999 || corr_k[i]<-999 ){ std::cout << "ERROR: TNtupleAnalyzer::getCorrValueFit: W correction fit not initialised! Index " <<  i << std::endl; return -999; }
  }

  if ( !USE_FIT_BINS ){
    double m_mt=selVal(MT,ind);
    if ( m_mt > MT_CORR_MAX ) return 1;
    if ( m_corr_d < -900 || m_corr_k < -900 ){
      int p_ind=getPInd( event_s->alltau_decay->at(ind) );
      m_corr_d=corr_d[p_ind];
      m_corr_k=corr_k[p_ind];
    }
    return ( m_corr_d+m_mt * m_corr_k );
  }

  //from here if unit size bins for fit are used, starting at -0.5
  Double_t n_mt=selVal(MT,ind)/10.; //FIXME
  if (n_mt<0) return -1;
  if (n_mt>(nFIT_BINS-1)) return 1; //for mT>XX, FIXME

  if ( m_corr_d < -900 || m_corr_k < -900 ){
    int p_ind=getPInd( event_s->alltau_decay->at(ind) );
    m_corr_d=corr_d[p_ind];
    m_corr_k=corr_k[p_ind];
  }

  Double_t ret= m_corr_d+(n_mt-0.5)*m_corr_k; //since -0.5 on fitted histo corresponds to mt=0, and +6.5 to mt=70

  return ret;
}

Double_t FFCalculator::getCorrValueFitErr(Double_t m_mt, Int_t ind){
  Double_t n_mt;
  Double_t ret;

  int p_ind=getPInd( event_s->alltau_decay->at(ind) );
  if ( USE_FIT_BINS ){
    n_mt=m_mt/10.; //FIXME
    if (m_mt==-999) n_mt=selVal(MT,ind)/10.;
    //  if (n_mt<0) return ( this->getCorrValueFitErr(40) ); //average uncertainty - the middle fitted bin //XXX
    if (n_mt<0) return ( this->getCorrValueFitErr( FIT_BINS[ (nFIT_BINS-1)/2 ] , ind ) ); //average uncertainty - the middle fitted bin //XXX
    if (n_mt>(nFIT_BINS-1)) return 0; //for mT>70, no uncertainty due to fit
    ret= corr_d[p_ind]+(n_mt-0.5)*corr_k[p_ind]; //since -0.5 on fitted histo corresponds to mt=0, and +6.5 to mt=70
  } else{
    n_mt=m_mt;
    if ( n_mt>MT_CORR_MAX ) return 0;
    if (m_mt==-999) n_mt=selVal(MT,ind);
    if ( n_mt<0 ) return( this->getCorrValueFitErr( 40 , ind ) );
    ret= corr_d[p_ind]+n_mt*corr_k[p_ind];
  }

  if (ret==0) return -999;

  /*
   *   //correlated
     Double_t err_hi=  fabs(  (corr_d+corr_d_err)  +  (n_mt-0.5)*  (corr_k+corr_k_err)  -  ret ) / ret;
       Double_t err_lo=  fabs(  (corr_d-corr_d_err)  +  (n_mt-0.5)*  (corr_k-corr_k_err)  -  ret ) / ret;
         if ( err_hi > err_lo ) return err_hi; else return err_lo;
  */

  /*
   *   //anti-correlated
     Double_t err_hi=  fabs(  (corr_d+corr_d_err)  +  (n_mt-0.5)*  (corr_k-corr_k_err)  -  ret ) / ret;
       Double_t err_lo=  fabs(  (corr_d-corr_d_err)  +  (n_mt-0.5)*  (corr_k+corr_k_err)  -  ret ) / ret;
         if ( err_hi > err_lo ) return err_hi; else return err_lo;
  */

  //the correct way
  double y_err2=corr_k_err[p_ind]*corr_k_err[p_ind] * ( corr_SSxxOverN[p_ind] + pow( n_mt -corr_avg_x[p_ind], 2) );
  return ( sqrt(y_err2)/ret );

}

double FFCalculator::getCorrValue(const double value, const int err, TH1D* h_corr){

  int ib=h_corr->FindBin( value );
  if ( err == 0 ) return h_corr->GetBinContent(ib);
  if ( err == 1 ) return h_corr->GetBinError(ib);

  return 1;
}

TH1D* FFCalculator::calcToyError(const std::vector<TH1D*> bg_est[NERR+1], const int ind ){

  TH1D* h_ret=new TH1D( *bg_est[0].at(ind) );

  for (int ib=0; ib<=h_ret->GetNbinsX(); ib++){
    double sum = 0;
    for (int i=1; i<=NERR; i++)
      sum+=bg_est[i].at(ind)->GetBinContent(ib);
    double mean= sum/NERR;
    double sq_diff_sum = 0;
    for (int i=1; i<=NERR; i++)
      sq_diff_sum+=pow( bg_est[i].at(ind)->GetBinContent(ib) - mean , 2);
    double std_dev= sqrt( sq_diff_sum / NERR );
    h_ret->SetBinError( ib , std_dev );
  }

  return h_ret;
}

TH1D* FFCalculator::calcToyError(TH1D* bg_est[NERR+1]){

  TH1D* h_ret=new TH1D( *bg_est[0] );

  for (int ib=0; ib<=h_ret->GetNbinsX(); ib++){
    double sum = 0;
    cout << bg_est[0]->GetBinContent(ib) << " " << bg_est[1]->GetBinContent(ib) << " " << bg_est[2]->GetBinContent(ib) << " " << bg_est[3]->GetBinContent(ib) << endl;
    for (int i=1; i<=NERR; i++){
      sum+=bg_est[i]->GetBinContent(ib);
    }
    double mean= sum/NERR;
    //double mean=h_ret->GetBinContent(ib);
    double sq_diff_sum = 0;
    for (int i=1; i<=NERR; i++)
      sq_diff_sum+=pow( bg_est[i]->GetBinContent(ib) - mean , 2);
    double std_dev= sqrt( sq_diff_sum / NERR );
    h_ret->SetBinError( ib , std_dev );
  }

  return h_ret;
}



void FFCalculator::createSystRatio(const TString fin1, const TString fin2, const TString fout, const int mode, const TString plotfile, const int ratio, const int incl_stat_err){

  std::cout << "In TNtupleAnalyzer::createSystRatio, creating " << fout << "...\t" << flush;

  TString xlabel="";
  TString hname="hh_";
  //  if ( description.Contains("looseSR") ) hname+="l_"; else 
  hname+="t_";
  if ( fout.Contains("_mt_")   || fout.Contains("_mt.")   ){ hname+="mt";   xlabel=labelMt;   }
  if ( fout.Contains("_mvis_") || fout.Contains("_mvis.") ){ hname+="mvis"; xlabel=labelMvis; }
  if ( fout.Contains("_pt_")   || fout.Contains("_pt.")   ){ hname+="pt";   xlabel=labelPt;   }

  TFile f1(fin1);
  TH1D* h1 = (TH1D*) f1.Get(hname);
  //  std::cout << fin1 << " " << f1.IsZombie() << " " << h1 << std::endl;
  TFile f2(fin2);
  TH1D* h2 = (TH1D*) f2.Get(hname);

  TH1D* h3; 

  if (ratio){  //ratio: for corrections
    h3=(TH1D*) h2->Clone("corr");
    h3->Divide(h1); //if a bin in either h1 or h2 is 0, it will be 0 in h3
    for (int i=0; i<=h3->GetNbinsX(); i++){
      if ( h3->GetBinContent(i)<1e-6 ) h3->SetBinContent( i , 1 );
    }
  } else{  //relative difference: for uncertainties
    h3=(TH1D*) h1->Clone("sys");
    h3->Add(h2,-1); //if a bin in either h1 or h2 is 0, it will be 0 in h3
    for (int i=0; i<=h3->GetNbinsX(); i++){
      h3->SetBinContent( i , fabs( h3->GetBinContent(i) ) );
    }
    h3->Divide(h2);
    //    h3->Divide(h2); //if a bin in either h1 or h2 is 0, it will be 0 in h3
    //    for (int i=0; i<h3->GetNbinsX(); i++){
    //      h3->SetBinContent( i , fabs( 1 - h3->GetBinContent(i) ) );
    //    }
    if (incl_stat_err){ //incl. stat unc. of the syst. unc. in the syst. unc.
      for (int i=0; i<=h3->GetNbinsX(); i++){
	double bc=h3->GetBinContent(i);
        double bcerr=h3->GetBinError(i);
	h3->SetBinContent( i , sqrt( bc*bc + bcerr*bcerr ) );
      }
    }
  }

  TFile f(fout,"RECREATE");
  h3->Write();
  f.Close();

  std::cout << "...done" << std::endl;

  if (plotfile=="") return;




  Int_t m_color=0;
  TString desc="non-closure ";
  TString l2="Sim";
  if (mode & _W_JETS)                 {    m_color=color_Wjets; desc+=vlabel[0]; }
  else if (mode & _DY){    m_color=color_DY_J;  desc+=vlabel[1]; }
  else if (mode & _TT){    m_color=color_TT_J;  desc+=vlabel[4]; }
  else if (mode & _QCD)               {    m_color=color_QCD;   desc+=vlabel[7]; l2="CR"; }
  h1->SetMarkerColor(m_color);
  h2->SetMarkerColor(m_color);
  h1->SetLineColor(m_color);
  h2->SetLineColor(m_color);

  TLegend *leg = new TLegend(0.55,0.68,0.89,0.88);
  //    leg = new TLegend(0.55,0.15,0.89,0.35);                                                                                                                                                                                
  leg->AddEntry(h1,"FF","lep");
  leg->AddEntry(h2,l2,"lep");

  this->makeRatioPlot(h1, h2, plotfile, desc, xlabel, leg);

}

void FFCalculator::createFitSystRatio(const TString FF1, const TString FF2, const TString pname1, const TString pname2, const int ind){
  Double_t m_corr_d1, m_corr_k1, m_corr_d_err1, m_corr_k_err1, m_corr_SSxxOverN1, m_corr_avg_x1;
  Double_t m_corr_d2, m_corr_k2, m_corr_d_err2, m_corr_k_err2, m_corr_SSxxOverN2, m_corr_avg_x2;
  this->doCorrFit(FF1, pname1, m_corr_d1, m_corr_k1, m_corr_d_err1, m_corr_k_err1, m_corr_SSxxOverN1, m_corr_avg_x1 );
  this->doCorrFit(FF2, pname2, m_corr_d2, m_corr_k2, m_corr_d_err2, m_corr_k_err2, m_corr_SSxxOverN2, m_corr_avg_x2 );

  sys_corr_d[ind] = m_corr_d1 - m_corr_d2;
  sys_corr_k[ind] = m_corr_k1 - m_corr_k2;

  std::cout << "createFitSystRatio: " << ind << " d1= " << m_corr_d1 << "\t k1= " << m_corr_k1 << std::endl;
  std::cout << "createFitSystRatio: " << ind << " d2= " << m_corr_d2 << "\t k2= " << m_corr_k2 << std::endl;
}

void FFCalculator::initCorrFit(const TString filename[NB_MTCORR], const TString plotfilename[NB_MTCORR], const TString formfilename){
  for (int i=0; i<NB_MTCORR; i++){
    this->doCorrFit(filename[i], plotfilename[i], corr_d[i], corr_k[i], corr_d_err[i], corr_k_err[i], corr_SSxxOverN[i], corr_avg_x[i] );
    if (formfilename!="") std::cout << "doCorrFit: " << i << " d= " << corr_d[i] << "\t k= " << corr_k[i] << std::endl;
  }

  //FIXME: only works for separate 1p/3p fit for now
  if ( formfilename!="" && NB_MTCORR==2 ){
    double d1=corr_d[0]-(5./10.)*corr_k[0];
    double k1=corr_k[0]/10;
    double d3=corr_d[1]-(5./10.)*corr_k[1];
    double k3=corr_k[1]/10;

    TString form="(x[0]<70)*((x[1]<4.5)*("; form+=k1; form+="*x[0]+"; form+=d1; form+=")+"; //1p
    form+="(x[1]>4.5)*("; form+=k3; form+="*x[0]+"; form+=d3; form+=")"; //3p
    form+=")+(x[0]>=70)"; //1 for mT>70             
    TFormula mtCorrection("form_mtCorr", form ); //parameters: 0 - mT , 1 - decayMode
    
    TFile* file = new TFile(formfilename, "recreate");
    mtCorrection.Write();
    //    file->WriteObject(factor, "ff");
    file->Close();
  }

}

void FFCalculator::doCorrFit(const TString filename, const TString plotfilename, 
				Double_t &m_corr_d, Double_t &m_corr_k, Double_t &m_corr_d_err, Double_t &m_corr_k_err, Double_t &m_corr_SSxxOverN, Double_t &m_corr_avg_x){

  TFile f(filename);
  TH1D *m_corr_histo_raw=(TH1D*)f.Get("c_t"); //mf
  TH1D *m_corr_histo; //mf
  //  if (!m_corr_histo) std::cout << "doCorrFit: histo c_t not found in " << filename << std::endl;

  TCanvas c1;

  if (m_corr_histo_raw){ //mf
    if (USE_FIT_BINS){
      m_corr_histo=(TH1D*)m_corr_histo_raw->Clone(); //mf
      m_corr_histo->SetTitle("");
      //  m_corr_histo->GetXaxis()->SetRangeUser(-0.5,MT_FIT_UP_TO+1); //6.5 for up to 70 GeV
      m_corr_histo->GetXaxis()->SetRangeUser(-0.5,MT_FIT_UP_TO); //6.5 for up to 70 GeV
      for (unsigned i=0; i<nFIT_BINS; i++){
	//    TString tmp; tmp+=p_mt_v[i]; tmp+="-"; tmp+=p_mt_v[i+1];
	TString tmp; tmp+=FIT_BINS[i]; tmp+="-"; tmp+=FIT_BINS[i+1];
	m_corr_histo->GetXaxis()->SetBinLabel(i+1,tmp);
      }
    }
    else{ //mf
      m_corr_histo=new TH1D("c_"+(TString)m_corr_histo_raw->GetName(),"",nFIT_BINS,0,FIT_BINS[nFIT_BINS-1]+FIT_BINS[1]-FIT_BINS[0]); //mf
      for (unsigned ib=1; ib<=nFIT_BINS; ib++){
	m_corr_histo->SetBinContent( ib , m_corr_histo_raw->GetBinContent(ib) );
	m_corr_histo->SetBinError( ib , m_corr_histo_raw->GetBinError(ib) );
      }
    } //mf
    m_corr_histo->SetYTitle("normalised FF");
    m_corr_histo->Scale( 1/m_corr_histo->GetBinContent(nFIT_BINS) );
  } else{
    m_corr_histo=(TH1D*)f.Get("corr");
    if (!m_corr_histo) std::cout << "doCorrFit: histo corr or c_t not found in " << filename << std::endl;
    m_corr_histo->SetTitle("");
    //    m_corr_histo->GetXaxis()->SetRangeUser(0,80); //6.5 for up to 70 GeV
    m_corr_histo->SetYTitle("FF");
  }
  if (USE_FIT_BINS){
    m_corr_histo->Fit("pol1","Q","",-0.5,MT_FIT_UP_TO);
  }else{
    if (DEBUG) m_corr_histo->Fit("pol1","" ,"",0,80);
    else       m_corr_histo->Fit("pol1","Q","",0,80);
  }
  TF1 *fitres = m_corr_histo->GetFunction("pol1");
  m_corr_histo->SetXTitle(labelMt);
  
  m_corr_d=fitres->GetParameter(0);
  m_corr_k=fitres->GetParameter(1);
  m_corr_d_err=fitres->GetParError(0);
  m_corr_k_err=fitres->GetParError(1);

  Int_t nfit=fitres->GetNumberFitPoints();

  m_corr_avg_x=0;
  for (int i=1; i<=nfit; i++){
    m_corr_avg_x+=m_corr_histo->GetBinCenter(i)*1.0/nfit;
  }
  //cout << m_corr_avg_x << std::endl;

  m_corr_SSxxOverN=0;
  for (int i=1; i<=nfit; i++){
    m_corr_SSxxOverN+=pow( m_corr_histo->GetBinCenter(i)-m_corr_avg_x , 2)/nfit;
  }
  //cout << m_corr_SSxxOverN << std::endl;
  m_corr_histo->GetYaxis()->SetRangeUser(0.0,1.3); //6.5 for up to 70 GeV

  if (plotfilename!="") gPad->SaveAs(plotfilename+".png");

  f.Close();
}

void FFCalculator::applyFF(TString outfile, const std::vector<Int_t> mode, const Int_t categoryMode, Int_t cuts, TString fname){  

  TFile* ff_file;

  TString channelString = getChannelString(categoryMode);
  fname.ReplaceAll("XXXXX",channelString);
  TString catString = getCatString_noSel(categoryMode);
  if( (categoryMode & _CATFRAC_MT || categoryMode & _CATFRAC_ET || categoryMode & _CATFRAC_TT)  ) fname.ReplaceAll("ZZZZZ",catString);

  cout << "FF file: " << fname << endl;
  //fname.ReplaceAll("/incl/","/SS_incl/");
  //fname.ReplaceAll("/incl/","/mc_incl/");
  //cout << "FF file: " << fname << endl;
  ff_file = TFile::Open(fname);
  FakeFactor* ff    = (FakeFactor*)ff_file->Get("ff_comb");
  FakeFactor* ff_tt; FakeFactor* ff_w; FakeFactor* ff_qcd_os;
  if(CHAN!=kTAU)ff_tt = (FakeFactor*)ff_file->Get("ff_tt");
  if(CHAN!=kTAU)ff_w = (FakeFactor*)ff_file->Get("ff_w");
  if(CHAN!=kTAU)ff_qcd_os = (FakeFactor*)ff_file->Get("ff_qcd_os");
  string frac_w("frac_w");
  string frac_qcd("frac_qcd");
  string frac_tt("frac_tt");
  string frac_dy("frac_dy");

  Double_t fillVal;
  Int_t tau_ind=0;
  vector<double> inputs;
  Int_t NV = mode.size();

  for(Int_t ni=0; ni<NV; ni++){
    loadFile(preselection_data,"Events");
    Int_t nentries = Int_t(event_s->fChain->GetEntries());
    cout << nentries << endl;
    cout << "Cuts: " << cuts << endl;
    TString outstring;
    if( mode.at(ni) & MVIS ) outstring = outfile+"_mvis.root";
    else if( mode.at(ni) & M2T ) outstring = outfile+"_mt2.root";
    else if( mode.at(ni) & PT )outstring = outfile+"_pt.root";
    else if( mode.at(ni) & MT )outstring = outfile+"_mt.root";
    else if( mode.at(ni) & LEPPT )outstring = outfile+"_lepPt.root";
    else if( mode.at(ni) & MVAMET )outstring = outfile+"_mvamet.root";
    else if( mode.at(ni) & MET )outstring = outfile+"_met.root";
    else if( mode.at(ni) & SVFIT )outstring = outfile+"_svfit.root";
    else{
      cout << "Error: Wrong mode specified in FFCalculator::applyFF" << endl;
      exit(0);
    }
    
    outstring.ReplaceAll(  ".root", catString+".root" );
    TString fracString = getFracString(categoryMode);
    outstring.ReplaceAll( ".root", fracString+".root" );
    cout << outstring << endl;
    
    TFile *f = new TFile(outstring,"RECREATE");
    TH1D* fakefactor_histo;
    if( mode.at(ni) & MVIS) fakefactor_histo = new TH1D("hh_t_mvis","",nbins_mvis,hist_min_mvis,hist_max_mvis);
    else if( mode.at(ni) & M2T) fakefactor_histo = new TH1D("hh_t_mt2","",nbins_mt2,hist_min_mt2,hist_max_mt2);
    else if( mode.at(ni) & PT) fakefactor_histo = new TH1D("hh_t_pt","",nbins_pt,hist_min_pt,hist_max_pt);
    else if( mode.at(ni) & MT) fakefactor_histo = new TH1D("hh_t_mt","",nbins_mt,hist_min_mt,hist_max_mt);
    else if( mode.at(ni) & LEPPT) fakefactor_histo = new TH1D("hh_t_lepPt","",nbins_lepPt,hist_min_lepPt,hist_max_lepPt);
    else if( mode.at(ni) & MVAMET) fakefactor_histo = new TH1D("hh_t_mvamet","",nbins_mvamet,hist_min_mvamet,hist_max_mvamet);
    else if( mode.at(ni) & MET) fakefactor_histo = new TH1D("hh_t_met","",nbins_met,hist_min_met,hist_max_met);
    else if( mode.at(ni) & SVFIT) fakefactor_histo = new TH1D("hh_t_svfit","",nbins_svfit,hist_min_svfit,hist_max_svfit);
    for (Int_t jentry=0; jentry<nentries;jentry++) {
      event_s->GetEntry(jentry);
      
      if (   this->isInSR(mode.at(ni),tau_ind) && this->isLoose(mode.at(ni),tau_ind)  && ( !cuts || this->passesCuts(cuts,tau_ind) )  ) { //!cuts for performance
        fillVal=this->selVal(mode.at(ni),tau_ind);
        inputs.clear();
        this->getInputs(inputs, tau_ind);
        double ffvalue;
        if ( !fulfillCategory(categoryMode) ) continue;
        if( mode.at(ni) & _W_JETS ) ffvalue = ff_w->value(inputs)*ff_w->value(inputs,frac_w);
        else if( mode.at(ni) & _TT ) ffvalue = ff_tt->value(inputs)*ff_tt->value(inputs,frac_tt);
        else if( mode.at(ni) & _DY ) ffvalue = ff_w->value(inputs)*ff_w->value(inputs,frac_dy);
        else if( mode.at(ni) & _QCD ) ffvalue = ff_qcd_os->value(inputs)*ff_qcd_os->value(inputs,frac_qcd);
        else ffvalue = ffvalue = ff->value(inputs);
        //cout << "value: " << fillVal << " and FF: " << ffvalue << " " << ffvalue*event_s->weight_sf << endl;
        fakefactor_histo->Fill(fillVal, ffvalue*event_s->weight_sf);        
        
      }
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout << fakefactor_histo->Integral() << endl;
    this->subtractBackground(fakefactor_histo, fname, mode.at(ni), categoryMode, cuts);
    cout << fakefactor_histo->Integral() << endl;
    for(int i=0; i<fakefactor_histo->GetNbinsX(); i++){
      if(fakefactor_histo->GetBinContent(i)<0) fakefactor_histo->SetBinContent(i,0);
    }
    f->cd();
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    //cout << "Bin contents: " << endl;
    //for(int i=0; i<fakefactor_histo->GetNbinsX(); i++) cout << i << ": " << fakefactor_histo->GetBinContent(i) << endl;
    
    
    //calc error FF
    /*TH1D *FFerr[NERR];
    TRandom3 r3;
    for (int i=0; i<NERR; i++){
      //    std::cout << "calc error FF: B " << i << std::endl;
      TString hn="ff_toyerr_"; if (i<10) hn+="0"; hn+=i;
      if( mode.at(ni) & MVIS) FFerr[i] = new TH1D(hn, "",nbins_mvis,hist_min_mvis,hist_max_mvis);
      if( mode.at(ni) & MT) FFerr[i] = new TH1D(hn, "",nbins_mt,hist_min_mt,hist_max_mt);
      if( mode.at(ni) & PT) FFerr[i] = new TH1D(hn, "",nbins_pt,hist_min_pt,hist_max_pt);
      if( mode.at(ni) & SVFIT) FFerr[i] = new TH1D(hn, "",nbins_svfit,hist_min_svfit,hist_max_svfit);
      for (int xb=1; xb<fakefactor_histo->GetNbinsX(); xb++){
        Double_t binc=r3.Gaus( fakefactor_histo->GetBinContent(xb) , fakefactor_histo->GetBinError(xb)  );
        FFerr[i]->SetBinContent( xb , binc );
      }
    }
    
    for (int i=0; i<NERR; i++){
      FFerr[i]->Write();
      delete FFerr[i];
      }*/
    fakefactor_histo->Write();
    delete fakefactor_histo;
    f->Close();
    }
  
  delete ff;
  if(CHAN!=kTAU){delete ff_tt; delete ff_w; delete ff_qcd_os;}
  ff_file->Close();
}

/*void FFCalculator::applyFF(TString outfile, const std::vector<Int_t> mode, const Int_t categoryMode, TString fname, Int_t cuts){  

  TFile* ff_file;

  TString channelString = getChannelString(categoryMode);
  fname.ReplaceAll("XXXXX",channelString);
  TString catString = getCatString_noSel(categoryMode);
  if( (categoryMode & _CATFRAC_MT || categoryMode & _CATFRAC_ET)  ) fname.ReplaceAll("ZZZZZ",catString);

  cout << "FF file: " << fname << endl;
  //fname.ReplaceAll("/incl/","/SS_incl/");
  //fname.ReplaceAll("/incl/","/mc_incl/");
  //cout << "FF file: " << fname << endl;
  ff_file = TFile::Open(fname);
  FakeFactor* ff    = (FakeFactor*)ff_file->Get("ff_comb");
  FakeFactor* ff_tt = (FakeFactor*)ff_file->Get("ff_tt");
  FakeFactor* ff_w = (FakeFactor*)ff_file->Get("ff_w");
  FakeFactor* ff_qcd_os = (FakeFactor*)ff_file->Get("ff_qcd_os");
  string frac_w("frac_w");
  string frac_qcd("frac_qcd");
  string frac_tt("frac_tt");
  string frac_dy("frac_dy");

  Double_t fillVal;
  Int_t tau_ind=0;
  vector<double> inputs;
  Int_t NV = mode.size();

  for(Int_t ni=0; ni<NV; ni++){
    Int_t nentries = Int_t(event_s->fChain->GetEntries());
    cout << nentries << endl;
    cout << "Cuts: " << cuts << endl;
    TString outstring;
    if( mode.at(ni) & MVIS ) outstring = outfile+"_mvis.root";
    else if( mode.at(ni) & MT ) outstring = outfile+"_mt.root";
    else if( mode.at(ni) & PT )outstring = outfile+"_pt.root";
    else if( mode.at(ni) & SVFIT )outstring = outfile+"_svfit.root";
    else{
      cout << "Error: Wrong mode specified in FFCalculator::applyFF" << endl;
      exit(0);
    }
    
    outstring.ReplaceAll(  ".root", catString+".root" );
    TString fracString = getFracString(categoryMode);
    outstring.ReplaceAll( ".root", fracString+".root" );
    cout << outstring << endl;
    
    TFile *f = new TFile(outstring,"RECREATE");
    TH1D* fakefactor_histo;
    if( mode.at(ni) & MVIS) fakefactor_histo = new TH1D("hh_t_mvis","",nbins_mvis,hist_min_mvis,hist_max_mvis);
    else if( mode.at(ni) & MT) fakefactor_histo = new TH1D("hh_t_mt","",nbins_mt,hist_min_mt,hist_max_mt);
    else if( mode.at(ni) & PT) fakefactor_histo = new TH1D("hh_t_pt","",nbins_pt,hist_min_pt,hist_max_pt);
    else if( mode.at(ni) & SVFIT) fakefactor_histo = new TH1D("hh_t_svfit","",nbins_svfit,hist_min_svfit,hist_max_svfit);
    for (Int_t jentry=0; jentry<nentries;jentry++) {
      event_s->GetEntry(jentry);
      
      if (   this->isInSR(mode.at(ni),tau_ind) && this->isLoose(mode.at(ni),tau_ind)  && ( !cuts || this->passesCuts(cuts,tau_ind) )  ) { //!cuts for performance
        fillVal=this->selVal(mode.at(ni),tau_ind);
        inputs.clear();
        this->getInputs(inputs, tau_ind);
        double ffvalue;
        if ( !fulfillCategory(categoryMode) ) continue;
        if( mode.at(ni) & _W_JETS ) ffvalue = ff_w->value(inputs)*ff_w->value(inputs,frac_w);
        else if( mode.at(ni) & _TT ) ffvalue = ff_tt->value(inputs)*ff_tt->value(inputs,frac_tt);
        else if( mode.at(ni) & _DY ) ffvalue = ff_w->value(inputs)*ff_w->value(inputs,frac_dy);
        else if( mode.at(ni) & _QCD ) ffvalue = ff_qcd_os->value(inputs)*ff_qcd_os->value(inputs,frac_qcd);
        else ffvalue = ffvalue = ff->value(inputs);
        //cout << "value: " << fillVal << " and FF: " << ffvalue << " " << ffvalue*event_s->weight_sf << endl;
        fakefactor_histo->Fill(fillVal, ffvalue*event_s->weight_sf);        
        
      }
    }
    //cout << "Bin contents: " << endl;
    //for(int i=0; i<fakefactor_histo->GetNbinsX(); i++) cout << i << ": " << fakefactor_histo->GetBinContent(i) << endl;
    
    
    //calc error FF
    TH1D *FFerr[NERR];
    TRandom3 r3;
    for (int i=0; i<NERR; i++){
      //    std::cout << "calc error FF: B " << i << std::endl;
      TString hn="ff_toyerr_"; if (i<10) hn+="0"; hn+=i;
      if( mode.at(ni) & MVIS) FFerr[i] = new TH1D(hn, "",nbins_mvis,hist_min_mvis,hist_max_mvis);
      if( mode.at(ni) & MT) FFerr[i] = new TH1D(hn, "",nbins_mt,hist_min_mt,hist_max_mt);
      if( mode.at(ni) & PT) FFerr[i] = new TH1D(hn, "",nbins_pt,hist_min_pt,hist_max_pt);
      if( mode.at(ni) & SVFIT) FFerr[i] = new TH1D(hn, "",nbins_svfit,hist_min_svfit,hist_max_svfit);
      for (int xb=1; xb<fakefactor_histo->GetNbinsX(); xb++){
        Double_t binc=r3.Gaus( fakefactor_histo->GetBinContent(xb) , fakefactor_histo->GetBinError(xb)  );
        FFerr[i]->SetBinContent( xb , binc );
      }
    }
    
    for (int i=0; i<NERR; i++){
      FFerr[i]->Write();
      delete FFerr[i];
    }
    fakefactor_histo->Write();
    delete fakefactor_histo;
    f->Close();
  }
  
  delete ff;
  delete ff_tt;
  delete ff_w;
  delete ff_qcd_os;
  ff_file->Close();
  }*/

void FFCalculator::applyFF_tt_raw(TString outfile, const std::vector<Int_t> mode, const Int_t categoryMode, TString fname, Int_t cuts){  

  TFile* ff_file;

  TString channelString = getChannelString(categoryMode);
  fname.ReplaceAll("XXXXX",channelString);
  TString catString = getCatString_noSel(categoryMode);
  if( (categoryMode & _CATFRAC_MT || categoryMode & _CATFRAC_ET)  ) fname.ReplaceAll("ZZZZZ",catString);

  cout << "FF file: " << fname << endl;
  fname = "/afs/hephy.at/user/j/jbrandstetter/public/Htautau/FakeRate/20160511/tt/Vienna_newPT/fakeFactors_20160511.root";
  cout << "FF file: " << fname << endl;
  ff_file = TFile::Open(fname);
  FakeFactor* ff    = (FakeFactor*)ff_file->Get("ff_comb_vlooseAntiIso");
  FakeFactor* ff_w = (FakeFactor*)ff_file->Get("ff_raw_w_weighted");
  FakeFactor* ff_dy = (FakeFactor*)ff_file->Get("ff_raw_dy_weighted");
  FakeFactor* ff_tt = (FakeFactor*)ff_file->Get("ff_raw_tt_weighted");
  FakeFactor* ff_qcd = (FakeFactor*)ff_file->Get("ff_raw_qcd_ss_vlooseAntiIso_weighted");

  Double_t fillVal;
  Int_t tau_ind=0;
  vector<double> inputs;
  Int_t NV = mode.size();

  for(Int_t ni=0; ni<NV; ni++){
    Int_t nentries = Int_t(event_s->fChain->GetEntries());
    cout << nentries << endl;
    cout << "Cuts: " << cuts << endl;
    TString outstring;
    if( mode.at(ni) & MVIS ) outstring = outfile+"_mvis.root";
    else if( mode.at(ni) & MT ) outstring = outfile+"_mt.root";
    else if( mode.at(ni) & PT )outstring = outfile+"_pt.root";
    else{
      cout << "Error: Wrong mode specified in FFCalculator::applyFF" << endl;
      exit(0);
    }
    
    outstring.ReplaceAll(  ".root", catString+".root" );
    TString fracString = getFracString(categoryMode);
    outstring.ReplaceAll( ".root", fracString+".root" );
    cout << outstring << endl;
    
    TFile *f = new TFile(outstring,"RECREATE");
    TH1D* fakefactor_histo;
    if( mode.at(ni) & MVIS) fakefactor_histo = new TH1D("hh_t_mvis","",nbins_mvis,hist_min_mvis,hist_max_mvis);
    else if( mode.at(ni) & MT) fakefactor_histo = new TH1D("hh_t_mt","",nbins_mt,hist_min_mt,hist_max_mt);
    else if( mode.at(ni) & PT) fakefactor_histo = new TH1D("hh_t_pt","",nbins_pt,hist_min_pt,hist_max_pt);
    for (Int_t jentry=0; jentry<nentries;jentry++) {
      event_s->GetEntry(jentry);
      
      if (   this->isInSR(mode.at(ni),tau_ind) && this->isTight_alt(mode.at(ni),tau_ind)  && ( !cuts || this->passesCuts(cuts,tau_ind) )  ) { //!cuts for performance
        fillVal=this->selVal(mode.at(ni),tau_ind);
        inputs.clear();
        this->getInputs(inputs, tau_ind);
        double ffvalue;
        if ( !fulfillCategory(categoryMode) ) continue;
        if( mode.at(ni) & _W_JETS ) ffvalue = ff_w->value(inputs);
        else if( mode.at(ni) & _DY ) ffvalue = ff_w->value(inputs);
        else if( mode.at(ni) & _TT ) ffvalue = ff_w->value(inputs);
        else if( mode.at(ni) & _QCD ) ffvalue = ff_qcd->value(inputs);
        else ffvalue = ffvalue = ff->value(inputs);
        fakefactor_histo->Fill(fillVal, ffvalue*event_s->weight);
        /*if( mode.at(ni) & _QCD) {
          cout << event_s->alltau_pt->at(0) << " " << ffvalue << endl;
          for(int i=0; i<inputs.size();i++) cout << "Input " << i << ": " << inputs.at(i) << endl;
          }*/
        
      }
    }
    
    fakefactor_histo->Write();
    delete fakefactor_histo;
    f->Close();
  }
  
  delete ff;
  delete ff_w;
  delete ff_tt;
  delete ff_dy;
  delete ff_qcd;
  ff_file->Close();
}

void FFCalculator::applyFF_wUncertainties(TString outfile, const std::vector<Int_t> mode, const Int_t categoryMode, TString fname, Int_t cuts, Int_t tau_ind){  

  TFile* ff_file;
  
  TString channelString = getChannelString(categoryMode);
  fname.ReplaceAll("XXXXX",channelString);
  TString catString = getCatString_noSel(categoryMode);
  if( (categoryMode & _CATFRAC_MT || categoryMode & _CATFRAC_ET || categoryMode & _CATFRAC_TT)  ) fname.ReplaceAll("ZZZZZ",catString);
  //s_chan[CHAN]

  cout << "FF file: " << fname << endl;
  //fname.ReplaceAll("/incl/","/mc_incl/");
  //cout << "FF file: " << fname << endl;
  ff_file = TFile::Open(fname);
  FakeFactor* ff    = (FakeFactor*)ff_file->Get("ff_comb");
  //Int_t nfrac
  Double_t pt_def=50; Int_t dm_def=0; Double_t mt_def=50; Double_t mvis_def=50; Double_t muiso_def=0.025;
  vector<string> nominal_syst;
  if(CHAN==kTAU){nominal_syst.push_back("ff_comb"); }
  else{nominal_syst.push_back("ff_w"); nominal_syst.push_back("ff_qcd_os"); nominal_syst.push_back("ff_tt");}
  Int_t nsyst=nominal_syst.size();
  vector<Int_t> errmode;
  if(CHAN==kTAU){errmode.push_back(0); errmode.push_back(0);}
  else {errmode.push_back(0); errmode.push_back(0); errmode.push_back(1); errmode.push_back(1); errmode.push_back(2); errmode.push_back(2);} //This tells which systematic errors belong together
  Int_t nerr=errmode.size();
  vector<string> syst_err_up; vector<string> syst_err_down;
  if(CHAN==kTAU){
    syst_err_up.push_back("ff_qcd_syst_up"); syst_err_up.push_back("ff_qcd_stat_up");
    syst_err_down.push_back("ff_qcd_syst_down"); syst_err_down.push_back("ff_qcd_stat_down"); 
  }
  else{
    syst_err_up.push_back("ff_w_syst_up"); syst_err_up.push_back("ff_w_stat_up"); syst_err_up.push_back("ff_qcd_syst_up"); syst_err_up.push_back("ff_qcd_stat_up"); syst_err_up.push_back("ff_tt_syst_up"); syst_err_up.push_back("ff_tt_stat_up");
    syst_err_down.push_back("ff_w_syst_down"); syst_err_down.push_back("ff_w_stat_down"); syst_err_down.push_back("ff_qcd_syst_down"); syst_err_down.push_back("ff_qcd_stat_down"); syst_err_down.push_back("ff_tt_syst_down"); syst_err_down.push_back("ff_tt_stat_down");
  }
  
  Double_t fillVal;
  vector<Double_t> inputs;

  //calc error FF
  cout << "Calculating toy errors" << endl;
      
  TRandom r3;
  std::vector<double> toy_inputs(6);
  cout << "Starting with initialization of error toys: " << endl;

  //This loop is for adding the errors for different FF components
  double ********ff_err_comp = new double*******[1];
  for(Int_t itoys=0; itoys<1; itoys++){
    cout << itoys << ". iteration out of " << NERR << endl;
    ff_err_comp[itoys]=new double******[nsyst];
    for(Int_t ierr=0; ierr<nerr; ierr++){
      if(ierr<nsyst) ff_err_comp[itoys][ierr]=new double*****[nbins_mvis]; //only for max number of ff compononents, or less
      FakeFactor* ff_syst    = (FakeFactor*)ff_file->Get(nominal_syst.at(errmode.at(ierr)).c_str());
      for(Int_t imvis=0; imvis<nbins_mvis; imvis++){
        if(ierr<nsyst) ff_err_comp[itoys][ierr][imvis]=new double****[nbins_mt];
        for(Int_t imt=0; imt<nbins_mt; imt++){
          if(ierr<nsyst) ff_err_comp[itoys][ierr][imvis][imt]=new double***[nbins_pt];
          for(Int_t ipt=0; ipt<nbins_pt; ipt++){
            if(ierr<nsyst) ff_err_comp[itoys][ierr][imvis][imt][ipt]=new double**[w_dm_n];
            for(Int_t idm=0; idm<w_dm_n; idm++){
              if(ierr<nsyst) ff_err_comp[itoys][ierr][imvis][imt][ipt][idm]=new double*[w_njets_n];
              for(Int_t ijet=0; ijet<w_njets_n; ijet++){
                if(ierr<nsyst) ff_err_comp[itoys][ierr][imvis][imt][ipt][idm][ijet]=new double[w_muiso_n];
                for(Int_t imuiso=0; imuiso<w_muiso_n; imuiso++){                  
                  toy_inputs[0]=hist_min_pt+ ( (hist_max_pt-hist_min_pt)/nbins_pt)*ipt+1;
                  if(idm==0) toy_inputs[1]=0;
                  if(idm==1) toy_inputs[1]=10;
                  if(ijet==0) toy_inputs[2]=0;
                  if(ijet==1) toy_inputs[2]=1;
                  toy_inputs[3]=hist_min_mvis+ ( (hist_max_mvis-hist_min_mvis)/nbins_mvis)*imvis+1;
                  toy_inputs[4]=hist_min_mt+ ( (hist_max_mt-hist_min_mt)/nbins_mt)*imt+1;
                  toy_inputs[5]=muiso_def;
                  Double_t ff_val=ff_syst->value(toy_inputs);
                  Double_t err_up=ff_syst->value(toy_inputs,syst_err_up.at(ierr))-ff_val;
                  Double_t err_down=ff_val-ff_syst->value(toy_inputs,syst_err_down.at(ierr));
                  Double_t binc = (err_up+err_down)/2;
                  //ff_err_comp[itoys][errmode.at(ierr)][imvis][imt][ipt][idm][ijet][imuiso] = binc;
                  if(ierr>0 && errmode.at(ierr)==errmode.at(ierr-1)) ff_err_comp[itoys][errmode.at(ierr)][imvis][imt][ipt][idm][ijet][imuiso] = TMath::Sqrt( TMath::Power(binc,2)+ TMath::Power(ff_err_comp[itoys][errmode.at(ierr)][imvis][imt][ipt][idm][ijet][imuiso],2) );
                  else ff_err_comp[itoys][errmode.at(ierr)][imvis][imt][ipt][idm][ijet][imuiso] = binc;
                }
              }
            }
          }
        }
      }
      delete ff_syst;
    }
  }
  cout << "Starting with initialization of toys: " << endl;
  
  double ********ff_err_toys = new double*******[NERR];
  //Double_t ff_err_toys[NERR][nsyst][nbins_mvis][nbins_mt][nbins_pt][w_dm_n][p_iso_n];
  for(Int_t itoys=0; itoys<1; itoys++){
    cout << itoys << ". iteration out of " << NERR << endl;
    ff_err_toys[itoys]=new double******[nsyst];
    for(Int_t isyst=0; isyst<nsyst; isyst++){
      FakeFactor* ff_syst    = (FakeFactor*)ff_file->Get(nominal_syst.at(isyst).c_str());
      ff_err_toys[itoys][isyst]=new double*****[nbins_mvis];
      for(Int_t imvis=0; imvis<nbins_mvis; imvis++){
        ff_err_toys[itoys][isyst][imvis]=new double****[nbins_mt];
        for(Int_t imt=0; imt<nbins_mt; imt++){
          ff_err_toys[itoys][isyst][imvis][imt]=new double***[nbins_pt];
          for(Int_t ipt=0; ipt<nbins_pt; ipt++){
            ff_err_toys[itoys][isyst][imvis][imt][ipt]=new double**[w_dm_n];
            for(Int_t idm=0; idm<w_dm_n; idm++){
              ff_err_toys[itoys][isyst][imvis][imt][ipt][idm]=new double*[w_njets_n];
              for(Int_t ijet=0; ijet<w_njets_n; ijet++){
                ff_err_toys[itoys][isyst][imvis][imt][ipt][idm][ijet]=new double[w_muiso_n];
                for(Int_t imuiso=0; imuiso<w_muiso_n; imuiso++){
                  ff_err_toys[itoys][isyst][imvis][imt][ipt][idm][ijet][imuiso]=ff_err_comp[itoys][isyst][imvis][imt][ipt][idm][ijet][imuiso];
                  //ff_err_toys[itoys][isyst][imvis][imt][ipt][idm][ijet][imuiso]=ff_err_comp[itoys][isyst][imvis][imt][ipt][idm][ijet];
                }
              }
            }
          }
        }
      }
      delete ff_syst;
    }
  }
  
  
  Int_t NV = mode.size();
  //////////////////////////////////////////////////////////////////////////////////////////////////////////
  for(Int_t mi=0; mi<NV; mi++){

    r3.SetSeed(1);
    TH1D *fakefactor_histo[NERR+1]; TH1D *fakefactor_histo_Wjets[NERR+1]; TH1D *fakefactor_histo_DY[NERR+1]; TH1D *fakefactor_histo_QCD[NERR+1]; TH1D *fakefactor_histo_TT[NERR+1];
    loadFile(preselection_data,"Events");
    Int_t nentries = Int_t(event_s->fChain->GetEntries());
    cout << nentries << endl;
    cout << "Cuts: " << cuts << endl;
    TString outstring;
    Int_t nbins;
    Double_t min_bin, max_bin;
    if( mode.at(mi) & MVIS ) { outstring = outfile+"_mvis.root"; nbins=nbins_mvis; min_bin=hist_min_mvis; max_bin=hist_max_mvis; } 
    else if( mode.at(mi) & MT ) { outstring = outfile+"_mt.root"; nbins=nbins_mt; min_bin=hist_min_mt; max_bin=hist_max_mt; } 
    else if( mode.at(mi) & PT ) { outstring = outfile+"_pt.root"; nbins=nbins_pt; min_bin=hist_min_pt; max_bin=hist_max_pt; }
    else if( mode.at(mi) & SVFIT ) { outstring = outfile+"_svfit.root"; nbins=nbins_svfit; min_bin=hist_min_svfit; max_bin=hist_max_svfit; }
    else if( mode.at(mi) & M2T ) { outstring = outfile+"_mt2.root"; nbins=nbins_mt2; min_bin=hist_min_mt2; max_bin=hist_max_mt2; }
    else if( mode.at(mi) & MVAMET ) { outstring = outfile+"_mvamet.root"; nbins=nbins_mvamet; min_bin=hist_min_mvamet; max_bin=hist_max_mvamet; }
    else if( mode.at(mi) & MET ) { outstring = outfile+"_met.root"; nbins=nbins_met; min_bin=hist_min_met; max_bin=hist_max_met; }
    else if( mode.at(mi) & LEPPT ) { outstring = outfile+"_lepPt.root"; nbins=nbins_lepPt; min_bin=hist_min_lepPt; max_bin=hist_max_lepPt; }
    else if( mode.at(mi) & ETA ) { outstring = outfile+"_eta.root"; nbins=nbins_eta; min_bin=hist_min_eta; max_bin=hist_max_eta; }
    else if( mode.at(mi) & MMTOT ) { outstring = outfile+"_mttot.root"; nbins=nbins_mttot; min_bin=hist_min_mttot; max_bin=hist_max_mttot; }
    else{
      cout << "Error: Wrong mode specified in FFCalculator::getSystUncertainties" << endl;
      exit(0);
    }
    outstring.ReplaceAll(  ".root", catString+".root" );
    TString fracString = getFracString(categoryMode);
    outstring.ReplaceAll( ".root", fracString+".root" );
    
    TFile *f = new TFile(outstring,"RECREATE");
    
    TString histname;
    if( mode.at(mi) & MVIS) {histname="hh_t_mvis"; fakefactor_histo[0] = new TH1D(histname,"",nbins_mvis,hist_min_mvis,hist_max_mvis);}
    else if( mode.at(mi) & MT) {histname="hh_t_mt"; fakefactor_histo[0] = new TH1D(histname,"",nbins_mt,hist_min_mt,hist_max_mt);}
    else if( mode.at(mi) & PT) {histname="hh_t_pt"; fakefactor_histo[0] = new TH1D(histname,"",nbins_pt,hist_min_pt,hist_max_pt);}
    else if( mode.at(mi) & SVFIT) {histname="hh_t_svfit"; fakefactor_histo[0] = new TH1D(histname,"",nbins_svfit,hist_min_svfit,hist_max_svfit);}
    else if( mode.at(mi) & M2T) {histname="hh_t_mt2"; fakefactor_histo[0] = new TH1D(histname,"",nbins_mt2,hist_min_mt2,hist_max_mt2);}
    else if( mode.at(mi) & MVAMET) {histname="hh_t_mvamet"; fakefactor_histo[0] = new TH1D(histname,"",nbins_mvamet,hist_min_mvamet,hist_max_mvamet);}
    else if( mode.at(mi) & MET) {histname="hh_t_met"; fakefactor_histo[0] = new TH1D(histname,"",nbins_met,hist_min_met,hist_max_met);}
    else if( mode.at(mi) & LEPPT) {histname="hh_t_lepPt"; fakefactor_histo[0] = new TH1D(histname,"",nbins_lepPt,hist_min_lepPt,hist_max_lepPt);}
    else if( mode.at(mi) & ETA) {histname="hh_t_eta"; fakefactor_histo[0] = new TH1D(histname,"",nbins_eta,hist_min_eta,hist_max_eta);}
    else if( mode.at(mi) & MMTOT) {histname="hh_t_mttot"; fakefactor_histo[0] = new TH1D(histname,"",nbins_mttot,hist_min_mttot,hist_max_mttot);}
    else{
      cout << "Error: Wrong mode specified in FFCalculator::getSystUncertainties" << endl;
      exit(0);
    }

    for (Int_t jentry=0; jentry<nentries;jentry++) {
      event_s->GetEntry(jentry);
      if (   this->isInSR(mode.at(mi),tau_ind) && this->isLoose(mode.at(mi),tau_ind)  && ( !cuts || this->passesCuts(cuts,tau_ind) )  ) { //!cuts for performance
        if ( !fulfillCategory(categoryMode) ) continue;
        fillVal=this->selVal(mode.at(mi),tau_ind);
        inputs.clear();
        this->getInputs(inputs, tau_ind);
        double ffvalue;
        ffvalue = ffvalue = ff->value(inputs);
        fakefactor_histo[0]->Fill(fillVal, ffvalue*event_s->weight_sf);
      }
    }
    fakefactor_histo_Wjets[0] = (TH1D*)fakefactor_histo[0]->Clone("Wjets_err");
    fakefactor_histo_DY[0] = (TH1D*)fakefactor_histo[0]->Clone("DY_err");
    fakefactor_histo_QCD[0] = (TH1D*)fakefactor_histo[0]->Clone("QCD_err");
    fakefactor_histo_TT[0] = (TH1D*)fakefactor_histo[0]->Clone("TT_err");

    FakeFactor* ff_w; FakeFactor* ff_qcd; FakeFactor* ff_tt;
    if(CHAN!=kTAU){
      ff_w = (FakeFactor*)ff_file->Get(nominal_syst.at(0).c_str());
      ff_qcd = (FakeFactor*)ff_file->Get(nominal_syst.at(1).c_str());
      ff_tt = (FakeFactor*)ff_file->Get(nominal_syst.at(2).c_str());
    }

    for (int itoys=0; itoys<NERR; itoys++){
      TString hn="ff_toyerr_"; if (itoys<10) hn+="0"; hn+=itoys;
      if( mode.at(mi) & MVIS) fakefactor_histo[itoys+1] = new TH1D(hn, "",nbins_mvis,hist_min_mvis,hist_max_mvis);
      if( mode.at(mi) & MT) fakefactor_histo[itoys+1] = new TH1D(hn, "",nbins_mt,hist_min_mt,hist_max_mt);
      if( mode.at(mi) & PT) fakefactor_histo[itoys+1] = new TH1D(hn, "",nbins_pt,hist_min_pt,hist_max_pt);
      if( mode.at(mi) & SVFIT) fakefactor_histo[itoys+1] = new TH1D(hn, "",nbins_svfit,hist_min_svfit,hist_max_svfit);
      if( mode.at(mi) & M2T) fakefactor_histo[itoys+1] = new TH1D(hn,"",nbins_mt2,hist_min_mt2,hist_max_mt2);
      if( mode.at(mi) & MVAMET) fakefactor_histo[itoys+1] = new TH1D(hn,"",nbins_mvamet,hist_min_mvamet,hist_max_mvamet);
      if( mode.at(mi) & MET) fakefactor_histo[itoys+1] = new TH1D(hn,"",nbins_met,hist_min_met,hist_max_met);
      if( mode.at(mi) & LEPPT) fakefactor_histo[itoys+1] = new TH1D(hn,"",nbins_lepPt,hist_min_lepPt,hist_max_lepPt);
      if( mode.at(mi) & ETA) fakefactor_histo[itoys+1] = new TH1D(hn,"",nbins_eta,hist_min_eta,hist_max_eta);
      if( mode.at(mi) & MMTOT) fakefactor_histo[itoys+1] = new TH1D(hn,"",nbins_mttot,hist_min_mttot,hist_max_mttot);
    }
    for (int itoys=0; itoys<NERR; itoys++){
      TString hn="ff_toyerr_"; if (itoys<10) hn+="0"; hn+=itoys;
      fakefactor_histo_Wjets[itoys+1] = (TH1D*)fakefactor_histo[itoys+1]->Clone(hn+"Wjets");
      fakefactor_histo_DY[itoys+1] = (TH1D*)fakefactor_histo[itoys+1]->Clone(hn+"DY");
      fakefactor_histo_QCD[itoys+1] = (TH1D*)fakefactor_histo[itoys+1]->Clone(hn+"QCD");
      fakefactor_histo_TT[itoys+1] = (TH1D*)fakefactor_histo[itoys+1]->Clone(hn+"TT");
    }
    double toyvalues[NERR];    
    for (int itoys=0; itoys<NERR; itoys++) toyvalues[itoys] = r3.Gaus(0,1);
    for (int itoys=0; itoys<NERR; itoys++) cout << toyvalues[itoys] << endl;
    for (Int_t jentry=0; jentry<nentries;jentry++) {
      event_s->GetEntry(jentry);

      if(jentry % 10000 == 0) cout << jentry << "/" << nentries << endl;
      
      if (   this->isInSR(mode.at(mi),tau_ind) && this->isLoose(mode.at(mi),tau_ind)  && ( !cuts || this->passesCuts(cuts,tau_ind) )  ) { //!cuts for performance
        if ( !fulfillCategory(categoryMode) ) continue;
        /*if( mode.at(mi) & _0JET && event_s->njets!=0 ) continue;
        if( mode.at(mi) & _1JET && event_s->njets!=1 ) continue;
        if( mode.at(mi) & _2JET && event_s->njets<2 ) continue;*/
        fillVal=this->selVal(mode.at(mi),tau_ind);
        inputs.clear();
        this->getInputs(inputs, tau_ind);
        int pt_lookup = int( (inputs[0]-hist_min_pt)/((hist_max_pt-hist_min_pt)/nbins_pt) );
        int mvis_lookup = int( (inputs[3]-hist_min_mvis)/((hist_max_mvis-hist_min_mvis)/nbins_mvis) );
        int mt_lookup = int( (inputs[4]-hist_min_mt)/((hist_max_mt-hist_min_mt)/nbins_mt) );
        int dm_lookup = inputs[1] > 4 ? 1 : 0;
        int njet_lookup = inputs[2] > 0 ? 1 : 0;
        int muiso_lookup = 0;
        for(int ilook=0; ilook<w_muiso_n; ilook++){ if(inputs[5]>w_muiso_v[ilook] && inputs[5]<w_muiso_v[ilook+1]){ muiso_lookup = ilook; break;} }
        
        if(pt_lookup >= nbins_pt || mvis_lookup >= nbins_mvis || mt_lookup >= nbins_mt || dm_lookup >= 2 || muiso_lookup >= w_muiso_n) continue;

        //////////////////////////////////////////////////////////////////////////////////////////////////////////
        for (int itoys=0; itoys<NERR; itoys++){
          Double_t toyffvalue=0; Double_t toyffvalue_Wjets=0; Double_t toyffvalue_QCD=0; Double_t toyffvalue_DY=0; Double_t toyffvalue_TT=0;
          if(CHAN!=kTAU){
            toyffvalue += (ff_w->value(inputs,"frac_w"))*( ff_w->value(inputs)+toyvalues[itoys]*ff_err_toys[0][0][mvis_lookup][mt_lookup][pt_lookup][dm_lookup][njet_lookup][muiso_lookup] );
            toyffvalue += (ff_qcd->value(inputs,"frac_qcd"))*( ff_qcd->value(inputs)+toyvalues[itoys]*ff_err_toys[0][1][mvis_lookup][mt_lookup][pt_lookup][dm_lookup][njet_lookup][muiso_lookup] );
            toyffvalue += (ff_tt->value(inputs,"frac_tt"))*( ff_tt->value(inputs)+toyvalues[itoys]*ff_err_toys[0][2][mvis_lookup][mt_lookup][pt_lookup][dm_lookup][njet_lookup][muiso_lookup] );
            toyffvalue += (ff_w->value(inputs,"frac_dy"))*( ff_w->value(inputs)+toyvalues[itoys]*ff_err_toys[0][0][mvis_lookup][mt_lookup][pt_lookup][dm_lookup][njet_lookup][muiso_lookup] );
            
            toyffvalue_Wjets += (ff_w->value(inputs,"frac_w"))*( ff_w->value(inputs)+toyvalues[itoys]*ff_err_toys[0][0][mvis_lookup][mt_lookup][pt_lookup][dm_lookup][njet_lookup][muiso_lookup] );
            toyffvalue_Wjets += ff_qcd->value(inputs)*ff_qcd->value(inputs,"frac_qcd") + ff_tt->value(inputs)*ff_tt->value(inputs,"frac_tt") + ff_w->value(inputs)*ff_w->value(inputs,"frac_dy");
            toyffvalue_QCD   += (ff_qcd->value(inputs,"frac_qcd"))*( ff_qcd->value(inputs)+toyvalues[itoys]*ff_err_toys[0][1][mvis_lookup][mt_lookup][pt_lookup][dm_lookup][njet_lookup][muiso_lookup] );
            toyffvalue_QCD   += ff_w->value(inputs)*ff_w->value(inputs,"frac_w") + ff_tt->value(inputs)*ff_tt->value(inputs,"frac_tt") + ff_w->value(inputs)*ff_w->value(inputs,"frac_dy");
            toyffvalue_DY    += (ff_w->value(inputs,"frac_dy"))*( ff_w->value(inputs)+toyvalues[itoys]*ff_err_toys[0][0][mvis_lookup][mt_lookup][pt_lookup][dm_lookup][njet_lookup][muiso_lookup] );
            toyffvalue_DY    += ff_qcd->value(inputs)*ff_qcd->value(inputs,"frac_qcd") + ff_tt->value(inputs)*ff_tt->value(inputs,"frac_tt") + ff_w->value(inputs)*ff_w->value(inputs,"frac_w");
            toyffvalue_TT    += (ff_tt->value(inputs,"frac_tt"))*( ff_tt->value(inputs)+toyvalues[itoys]*ff_err_toys[0][2][mvis_lookup][mt_lookup][pt_lookup][dm_lookup][njet_lookup][muiso_lookup] );
            toyffvalue_TT    += ff_qcd->value(inputs)*ff_qcd->value(inputs,"frac_qcd") + ff_w->value(inputs)*ff_w->value(inputs,"frac_w") + ff_w->value(inputs)*ff_w->value(inputs,"frac_dy");

            fakefactor_histo[itoys+1]->Fill(fillVal, toyffvalue*event_s->weight_sf);
            fakefactor_histo_Wjets[itoys+1]->Fill(fillVal, toyffvalue_Wjets*event_s->weight_sf);
            fakefactor_histo_DY[itoys+1]->Fill(fillVal, toyffvalue_DY*event_s->weight_sf);
            fakefactor_histo_QCD[itoys+1]->Fill(fillVal, toyffvalue_QCD*event_s->weight_sf);
            fakefactor_histo_TT[itoys+1]->Fill(fillVal, toyffvalue_TT*event_s->weight_sf);
          }
          else{
            toyffvalue += ( ff->value(inputs)+toyvalues[itoys]*ff_err_toys[0][0][mvis_lookup][mt_lookup][pt_lookup][dm_lookup][njet_lookup][muiso_lookup] );
            fakefactor_histo[itoys+1]->Fill(fillVal, toyffvalue*event_s->weight_sf);
            fakefactor_histo_Wjets[itoys+1]->Fill(fillVal, event_s->weight_sf);
            fakefactor_histo_DY[itoys+1]->Fill(fillVal, event_s->weight_sf);
            fakefactor_histo_QCD[itoys+1]->Fill(fillVal, event_s->weight_sf);
            fakefactor_histo_TT[itoys+1]->Fill(fillVal, event_s->weight_sf);
          }

          
        }       
      }
    }
    if(CHAN!=kTAU){delete ff_w; delete ff_qcd; delete ff_tt;}
    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout << fakefactor_histo[0]->Integral() << endl;
    this->subtractBackground(fakefactor_histo[0], fname, mode.at(mi), categoryMode);
    cout << fakefactor_histo[0]->Integral() << endl;
    f->cd();
    

    //////////////////////////////////////////////////////////////////////////////////////////////////////////


    TH1D* h_wErr=this->calcToyError(fakefactor_histo);
    for (Int_t ie=0; ie<=nbins; ie++){
      Double_t staterr= fakefactor_histo[0]->GetBinError(ie);
      Double_t toyerr= h_wErr->GetBinError(ie);
      cout << ie << ".bin: " << fakefactor_histo[0]->GetBinContent(ie) << "+-" << staterr << "(stat)+-" << toyerr << "(syst)" << endl;
      fakefactor_histo[0]->SetBinError( ie,  sqrt(staterr*staterr + toyerr*toyerr )  );
    }

    h_wErr=this->calcToyError(fakefactor_histo_Wjets);
    cout << "---------Wjets-----------------" << endl;
    for (Int_t ie=0; ie<=nbins; ie++){
      Double_t staterr= fakefactor_histo_Wjets[0]->GetBinError(ie);
      Double_t toyerr= h_wErr->GetBinError(ie);
      cout << ie << ".bin: " << fakefactor_histo_Wjets[0]->GetBinContent(ie) << "+-" << staterr << "(stat)+-" << toyerr << "(syst)" << endl;
      fakefactor_histo_Wjets[0]->SetBinError( ie,  sqrt(staterr*staterr + toyerr*toyerr )  );
    }

    h_wErr=this->calcToyError(fakefactor_histo_DY);
    cout << "---------DY-----------------" << endl;
    for (Int_t ie=0; ie<=nbins; ie++){
      Double_t staterr= fakefactor_histo_DY[0]->GetBinError(ie);
      Double_t toyerr= h_wErr->GetBinError(ie);
      cout << ie << ".bin: " << fakefactor_histo_DY[0]->GetBinContent(ie) << "+-" << staterr << "(stat)+-" << toyerr << "(syst)" << endl;
      fakefactor_histo_DY[0]->SetBinError( ie,  sqrt(staterr*staterr + toyerr*toyerr )  );
    }

    h_wErr=this->calcToyError(fakefactor_histo_QCD);
    cout << "---------QCD-----------------" << endl;
    for (Int_t ie=0; ie<=nbins; ie++){
      Double_t staterr= fakefactor_histo_QCD[0]->GetBinError(ie);
      Double_t toyerr= h_wErr->GetBinError(ie);
      cout << ie << ".bin: " << fakefactor_histo_QCD[0]->GetBinContent(ie) << "+-" << staterr << "(stat)+-" << toyerr << "(syst)" << endl;
      fakefactor_histo_QCD[0]->SetBinError( ie,  sqrt(staterr*staterr + toyerr*toyerr )  );
    }

    h_wErr=this->calcToyError(fakefactor_histo_TT);
    cout << "---------TT-----------------" << endl;
    for (Int_t ie=0; ie<=nbins; ie++){
      Double_t staterr= fakefactor_histo_TT[0]->GetBinError(ie);
      Double_t toyerr= h_wErr->GetBinError(ie);
      cout << ie << ".bin: " << fakefactor_histo_TT[0]->GetBinContent(ie) << "+-" << staterr << "(stat)+-" << toyerr << "(syst)" << endl;
      fakefactor_histo_TT[0]->SetBinError( ie,  sqrt(staterr*staterr + toyerr*toyerr )  );
    }
    
      
    for (int i=0; i<NERR; i++){
      delete fakefactor_histo[i+1];
      delete fakefactor_histo_Wjets[i+1];
      delete fakefactor_histo_DY[i+1];
      delete fakefactor_histo_QCD[i+1];
      delete fakefactor_histo_TT[i+1];
    }
    fakefactor_histo[0]->Write();
    fakefactor_histo_Wjets[0]->Write();
    fakefactor_histo_DY[0]->Write();
    fakefactor_histo_QCD[0]->Write();
    fakefactor_histo_TT[0]->Write();
    delete fakefactor_histo[0];
    delete fakefactor_histo_Wjets[0];
    delete fakefactor_histo_DY[0];
    delete fakefactor_histo_QCD[0];
    delete fakefactor_histo_TT[0];
    f->Close();
    
  }//loop over modes
  
  for(Int_t itoys=0; itoys<1; itoys++){
    for(Int_t isyst=0; isyst<nsyst; isyst++){
      for(Int_t imvis=0; imvis<nbins_mvis; imvis++){
        for(Int_t imt=0; imt<nbins_mt; imt++){
          for(Int_t ipt=0; ipt<nbins_pt; ipt++){
            for(Int_t idm=0; idm<w_dm_n; idm++){
              for(Int_t ijet=0; ijet<w_njets_n; ijet++){
                delete[] ff_err_toys[itoys][isyst][imvis][imt][ipt][idm][ijet];   
              }
              delete[] ff_err_toys[itoys][isyst][imvis][imt][ipt][idm];   
            }
            delete[] ff_err_toys[itoys][isyst][imvis][imt][ipt];   
          }
          delete[] ff_err_toys[itoys][isyst][imvis][imt];   
        }
        delete[] ff_err_toys[itoys][isyst][imvis];   
      }
      delete[] ff_err_toys[itoys][isyst];   
    }
    delete[] ff_err_toys[itoys];
  }
  delete[] ff_err_toys;

  for(Int_t itoys=0; itoys<1; itoys++){
    for(Int_t ierr=0; ierr<nsyst; ierr++){
      for(Int_t imvis=0; imvis<nbins_mvis; imvis++){
        for(Int_t imt=0; imt<nbins_mt; imt++){
          for(Int_t ipt=0; ipt<nbins_pt; ipt++){
            for(Int_t idm=0; idm<w_dm_n; idm++){
              for(Int_t ijet=0; ijet<w_njets_n; ijet++){
                delete[] ff_err_comp[itoys][ierr][imvis][imt][ipt][idm][ijet];
              }
              delete[] ff_err_comp[itoys][ierr][imvis][imt][ipt][idm];
            }
            delete[] ff_err_comp[itoys][ierr][imvis][imt][ipt];
          }
          delete[] ff_err_comp[itoys][ierr][imvis][imt];
        }
        delete[] ff_err_comp[itoys][ierr][imvis];
      }
      delete[] ff_err_comp[itoys][ierr];
    }
    delete[] ff_err_comp[itoys];
  }
  delete[] ff_err_comp;
  
  
  delete ff; 
  ff_file->Close();
}



void FFCalculator::getInputs(vector<double>&inputs, Int_t ind)
{
  if(CHAN==kTAU){
    inputs.push_back(event_s->alltau_pt->at(ind) );
    inputs.push_back(event_s->lep_pt);
    inputs.push_back(event_s->alltau_decay->at(ind) );
    inputs.push_back(event_s->njets);
    inputs.push_back(event_s->alltau_mvis->at(ind) );
    inputs.push_back(event_s->lep_iso);
  }
  else{
    inputs.push_back(event_s->alltau_pt->at(ind) );
    inputs.push_back(event_s->alltau_decay->at(ind) );
    inputs.push_back(event_s->njets);
    inputs.push_back(event_s->alltau_mvis->at(ind) );
    inputs.push_back(event_s->alltau_mt->at(ind) );
    inputs.push_back(event_s->lep_iso);
  }
  
}

void FFCalculator::getSystUncertainties(const Int_t mode, TString FFfile, const std::vector<TString> syst_file, TString outfile)
{
  TH1D* fakefactor_histo[NERR+1];
  TFile *f = new TFile(FFfile);
  TString ffname;
  if( mode & MVIS) ffname="hh_t_mvis";
  else if( mode & MT) ffname="hh_t_mt";
  else if( mode & PT) ffname = "hh_t_pt";
  else{
    cout << "Error: Wrong mode specified in FFCalculator::getSystUncertainties" << endl;
    exit(0);
  }

 fakefactor_histo[0] = (TH1D*) f->Get(ffname); //weighted ff are called
 if ( !fakefactor_histo[0] ) cout << "ERROR: TNtupleAnalyzer::calcBgEstFF : Histo " << ffname << " in File " << FFfile << " does not exist." << endl;

  for (int ie=0; ie<NERR; ie++){
    TString hn = "ff_toyerr_"; if (ie<10) hn+="0"; hn+=ie;
    fakefactor_histo[ie+1] = (TH1D*) f->Get(hn);
  }

  TH1D* h_wErr=this->calcToyError(fakefactor_histo);

  if(syst_file.size() > 0){

    TString vname;
    if (mode & MT) vname="mt";
    if (mode & MVIS) vname="mvis";
    if (mode & PT) vname="pt";
    
    for (unsigned is=0; is<syst_file.size(); is++){
      TString tmp=syst_file.at(is); tmp.ReplaceAll("XVARX",vname);
      TFile *fs = new TFile(tmp);
      TH1D* h_syst;
      Int_t nbins;
      if(mode & MVIS) nbins = nbins_mvis;
      else if(mode & MT) nbins = nbins_mt;
      else if(mode & PT) nbins = nbins_pt;
      h_syst = (TH1D*) fs->Get("sys");
      for (Int_t ie=0; ie<=nbins; ie++){
        Double_t systErr= h_syst->GetBinContent(ie);
        Double_t err= h_wErr->GetBinError(ie);
        Double_t val= h_wErr->GetBinContent(ie);
        h_wErr->SetBinError( ie,  sqrt(err*err + systErr*systErr*val*val )  );
      }
    }
  }

  TFile file1(outfile,"RECREATE");
  h_wErr->Write();
  file1.Close();
  
  
}


void FFCalculator::calc_nonclosure(const Int_t mode, const TString raw_ff, const TString compare_file, TString ff_output, const TString tight_cat, const Int_t doPlot, const Int_t subtractMC, const Int_t tau_ind){

  cout << "Calculating corrections for " << ff_output << endl;
  Int_t nentries = Int_t(event_s->fChain->GetEntries());
  cout << nentries << endl;

  TString sample;
  if(mode & _QCD) sample="_QCD";
  if(mode & _W_JETS) sample="_Wjets";
  if(mode & _TT) sample="_TT";
  if(!subtractMC) sample+="_MC";
  
  TH1D *closure_h;
  if(mode & _TT) closure_h= new TH1D("closure"+sample,"",nbins_mvis,hist_min_mvis,hist_max_mvis);
  else closure_h= new TH1D("closure"+sample,"",w_mvis_n,w_mvis_v);
  //TH1D *closure_h = new TH1D("closure"+sample,"",w_zpt_n,w_zpt_v);
  TFile *output = new TFile(ff_output.ReplaceAll(".root",tight_cat+".root"),"RECREATE");
  TH1D *output_h = new TH1D("nonclosure_mvis","",w_mvis_n,w_mvis_v);
  //TH1D *output_h = new TH1D("nonclosure_zpt","",w_zpt_n,w_zpt_v);
  TFile FF_lookup(raw_ff);
  TH1D* FF_lookup_h = nullptr;
  if( !raw_ff.Contains("_fitted") ) FF_lookup_h = (TH1D*) FF_lookup.Get("c_t"+tight_cat);
  vector<TGraphAsymmErrors*> fittedFFs;
  if( raw_ff.Contains("_fitted") ){
    TGraphAsymmErrors *dm0njet0 = (TGraphAsymmErrors*) FF_lookup.Get("dm0_njet0"+tight_cat); fittedFFs.push_back(dm0njet0);
    TGraphAsymmErrors *dm1njet0 = (TGraphAsymmErrors*) FF_lookup.Get("dm1_njet0"+tight_cat); fittedFFs.push_back(dm1njet0);
    TGraphAsymmErrors *dm0njet1 = (TGraphAsymmErrors*) FF_lookup.Get("dm0_njet1"+tight_cat); fittedFFs.push_back(dm0njet1);
    TGraphAsymmErrors *dm1njet1 = (TGraphAsymmErrors*) FF_lookup.Get("dm1_njet1"+tight_cat); fittedFFs.push_back(dm1njet1);
  }
  
  TFile compare(compare_file);
  Double_t FF_value=0;
  if(subtractMC){
    TString ff_inputHist="hh_l"; 
    TH1D* compare_l              = (TH1D*) compare.Get(ff_inputHist+"_mvis");
    TH1D* compare_l_MCsubtracted = (TH1D*) compare.Get(ff_inputHist+"_mvis_MCsubtracted");
    //TH1D* compare_l              = (TH1D*) compare.Get("hh_l_zpt");
    //TH1D* compare_l_MCsubtracted = (TH1D*) compare.Get("hh_l_zpt_MCsubtracted");
    TH1D* ratio_l                = (TH1D*)compare_l_MCsubtracted->Clone("ratio_l");
    ratio_l->Divide(compare_l);
    ///get unity histogram
    TH1D *unity_h = new TH1D("unity","",w_mvis_n,w_mvis_v);
    //TH1D *unity_h = new TH1D("unity","",w_zpt_n,w_zpt_v);
    for(int ibin=1; ibin<=unity_h->GetNbinsX(); ibin++) unity_h->SetBinContent(ibin,1.);
    ratio_l->Add(unity_h,-1);ratio_l->Scale(-1);
    TH1D* compare_t              = (TH1D*) compare.Get("hh_t"+tight_cat+"_mvis");
    TH1D* compare_t_MCsubtracted = (TH1D*) compare.Get("hh_t"+tight_cat+"_mvis_MCsubtracted");
    //TH1D* compare_t              = (TH1D*) compare.Get("hh_t_zpt");
    //TH1D* compare_t_MCsubtracted = (TH1D*) compare.Get("hh_t_zpt_MCsubtracted");

    //TFile nonclosure("fakefactor/data_mt/FF_corr_QCD_MCsum_noGen_nonclosure.root");
    //TH1D* nonclosure_h = (TH1D*) nonclosure.Get("nonclosure_smoothed");
    //TFile nonclosure_mt("fakefactor/data_mt/FF_corr_Wjets_MC_noGen_mtcorr.root");
    //TH1D* nonclosure_mt_h = (TH1D*) nonclosure_mt.Get("mt_corr_smoothed");
  
    for (Int_t jentry=0; jentry<nentries;jentry++) {
      event_s->GetEntry(jentry);
      if(jentry % 100000 == 0) cout << jentry << "/" << nentries << endl;
      if (mode & SR){
        if (  this->isInSR(mode,tau_ind) && this->isLoose(mode,tau_ind) ) {
          if( !raw_ff.Contains("_fitted") ) FF_value = FF_lookup_h->GetBinContent( this->getBin(mode|tau_ind)+1 );
          else if( raw_ff.Contains("_fitted") ){
            FF_value = this->getFittedBinContent( mode, fittedFFs );
          }
          closure_h->Fill(event_s->alltau_mvis->at(tau_ind),FF_value*event_s->weight_sf );
        }
      }
      else{
        if (  this->isInCR(mode,tau_ind) && this->isLoose(mode,tau_ind) ){
          if( !raw_ff.Contains("_fitted") ) FF_value = FF_lookup_h->GetBinContent( this->getBin(mode|tau_ind)+1 );
          else if( raw_ff.Contains("_fitted") ){
            FF_value = this->getFittedBinContent( mode, fittedFFs );
          }
          closure_h->Fill(event_s->alltau_mvis->at(tau_ind),FF_value*event_s->weight_sf );
        }
      }
      //if (  this->isInCR(mode,tau_ind) && this->isLoose(mode,tau_ind) ) closure_h->Fill(event_s->alltau_Zpt->at(tau_ind),FF_lookup_h->GetBinContent( this->getBin(mode|tau_ind)+1 )*nonclosure_h->GetBinContent( this->getWeightIndex_mvis(event_s->alltau_mvis->at(tau_ind) )+1 )*nonclosure_mt_h->GetBinContent( this->getWeightIndex_mt(event_s->alltau_mt->at(tau_ind) )+1 ) );
      //if (  this->isInCR(mode,tau_ind) && this->isLoose(mode,tau_ind) ) closure_h->Fill(event_s->alltau_Zpt->at(tau_ind),FF_lookup_h->GetBinContent( this->getBin(mode|tau_ind)+1 )*nonclosure_h->GetBinContent( this->getWeightIndex_mvis(event_s->alltau_mvis->at(tau_ind) )+1 ) ); 
    }

    closure_h->Multiply(ratio_l);
    output->cd();
    closure_h->Write();
  
    output_h = (TH1D*)compare_t->Clone("nonclosure");
    output_h->Add(compare_t_MCsubtracted,-1);
    compare_t->Add(compare_t_MCsubtracted,-1);
    compare_t->Write();
    output_h->Divide(closure_h);
  }
  else{ 
    TH1D* compare_t              = (TH1D*) compare.Get("hh_t"+tight_cat+"_mvis");
  
    for (Int_t jentry=0; jentry<nentries;jentry++) {
      event_s->GetEntry(jentry);
      if(jentry % 100000 == 0) cout << jentry << "/" << nentries << endl;
      if (mode & SR){
        if (  this->isInSR(mode,tau_ind) && this->isLoose(mode,tau_ind) ){
          if( !raw_ff.Contains("_fitted") ) FF_value = FF_lookup_h->GetBinContent( this->getBin(mode|tau_ind)+1 );
          else if( raw_ff.Contains("_fitted") ){
            FF_value = this->getFittedBinContent( mode, fittedFFs );
          }
          closure_h->Fill(event_s->alltau_mvis->at(tau_ind),FF_value*event_s->weight_sf );
        }
      }
      else{
        if (  this->isInCR(mode,tau_ind) && this->isLoose(mode,tau_ind) ){
          if( !raw_ff.Contains("_fitted") ) FF_value = FF_lookup_h->GetBinContent( this->getBin(mode|tau_ind)+1 );
          else if( raw_ff.Contains("_fitted") ){
            FF_value = this->getFittedBinContent( mode, fittedFFs );
          }
          closure_h->Fill(event_s->alltau_mvis->at(tau_ind),FF_value*event_s->weight_sf );
        }
      }
    }
    
    output->cd();
    closure_h->Write();
  
    output_h = (TH1D*)compare_t->Clone("nonclosure");
    output_h->Divide(closure_h);
  }

  TH1D* output_fit;
  /*if(CHAN==kTAU && calcVTightFF){
    output_fit=new TH1D("nonclosure_fit","",w_mvis_n,w_mvis_v);
    for(int i=1;i<=output_h->GetNbinsX();i++){
      
      if( i >= 9 ){output_fit->SetBinContent(i,output_h->GetBinContent(i)); output_fit->SetBinError(i,output_h->GetBinError(i));}
    }
  }
  else*/ output_fit = (TH1D*)output_h->Clone("nonclosure_fit");

  for(int i=1;i<=output_h->GetNbinsX();i++){
    if( output_h->GetBinContent(i) < 0 ) output_h->SetBinError(i,1.);
  }
  
  output->cd();
  output_fit->Write();

  GaussianKernelSmoother gsk;
  int ret=gsk.setInputHisto( output_fit );
  if ( ret != 0 ) return;
  gsk.set_doWeights(1);
  gsk.set_doIgnoreZeroBins(0);
  gsk.set_kernelDistance( "lin" );
  gsk.set_doWidthInBins(1);
  gsk.set_doErrors(1);
  //if(mode & _QCD) gsk.set_lastBinFrom(150);
  Double_t fitWidth;
  if(mode & _QCD) fitWidth=1.5; else if(mode & _W_JETS) fitWidth=1.5; else fitWidth=1.5;
  if(CHAN==kTAU) fitWidth=1.5;
  cout << "FitWidth: " << fitWidth << endl;
  gsk.setWidth(fitWidth);
  gsk.set_widthInBins_sf(1.115);
  //gsk.set_doWidthInBins(0);
  //gsk.setWidth(2*h->GetBinWidth(1));
  gsk.getSmoothHisto();
  TH1D *h2=gsk.returnSmoothedHisto();
  /*for(int i=1;i<=h2->GetNbinsX();i++){
    if(i<9){h2->SetBinContent(i,1);h2->SetBinError(i,0.1);}
    }*/
  h2->Write();

  gsk.set_doErrors(1);
  gsk.getContSmoothHisto();
  TGraphAsymmErrors *g=   gsk.returnSmoothedGraph();
  if(CHAN==kTAU){
    Double_t x_value; Double_t y_value; Double_t y_errorHigh; Double_t y_errorLow; Int_t counter;
    for(int i=0; i<g->GetN(); i++){
      g->GetPoint(i,x_value,y_value);
      if(x_value>=80){
        counter=i;
        y_errorHigh=g->GetErrorYhigh(i);
        y_errorLow=g->GetErrorYlow(i);
        break;
      }
    }
    for(int i=0; i<g->GetN(); i++){
      Double_t x; Double_t y; 
      g->GetPoint(i,x,y);
      //if(x<80) {g->SetPoint(i,x,y_value); g->SetPointEYhigh(i,y_errorHigh); g->SetPointEYlow(i,y_errorLow);}
    }
  }

  Double_t x185; Double_t y185;
  g->GetPoint(185,x185,y185);
  for(int i=0; i<g->GetN(); i++){
    Double_t x; Double_t y;
    if(i>185){
      g->GetPoint(i,x,y);
      g->SetPoint(i,x,y185);
    }
  }

  ///////////////////////////////////////////////////////////////
  /*int ilimit=0;
  Double_t limitValueHigh=0;
  Double_t limitValueLow=0;
  for(int i=0; i<g->GetN(); i++){
    Double_t x; Double_t y;
    g->GetPoint(i,x,y);
    if(x>=100 && ilimit==0) {
      limitValueHigh=g->GetErrorYhigh(i)/y;
      limitValueLow=g->GetErrorYlow(i)/y;
      //cout << y << " " << g->GetErrorYhigh(i) << " " << limitValueHigh << endl;
      ilimit=i;
    }
  }
  for(int i=0; i<g->GetN(); i++){
    Double_t x; Double_t y;
    g->GetPoint(i,x,y);
    if(x>100) {
      g->SetPointEYhigh(i,g->GetErrorYhigh(i)+(i-ilimit)*(limitValueHigh/50) );
      g->SetPointEYlow(i,g->GetErrorYlow(i)+(i-ilimit)*(limitValueLow/50) );
    }
    }*/

  ///////////////////////////////////////////////////////////////
  g->SetTitle("nonclosure"+sample);
  g->SetName("nonclosure"+sample);
  g->Write();

  TGraph *gup = (TGraphAsymmErrors*)g->Clone("nonclosure"+sample+"_up");
  gup->SetTitle("nonclosure"+sample+"_up");
  for(Int_t j=0;j<g->GetN();j++) gup->SetPoint(j,g->GetX()[j],g->GetErrorYhigh(j) );
  gup->Write();
  TGraph *gdown = (TGraphAsymmErrors*)g->Clone("nonclosure"+sample+"_down");
  gdown->SetTitle("nonclosure"+sample+"_down");
  for(Int_t j=0;j<g->GetN();j++) gdown->SetPoint(j,g->GetX()[j],g->GetErrorYlow(j) );
  gdown->Write();
  

  TCanvas *c2=new TCanvas();
  output_h->Draw("E");
  g->Draw("same LP");
  /*if(CHAN==kTAU && calcVTightFF){
    for(int i=1;i<=output_h->GetNbinsX();i++){
      if( i < 9 ){output_h->SetBinContent(i,0.); output_h->SetBinError(i,0.);}
    }
    }*/
  output_h->Draw("E same");
  output_h->SetXTitle("m_{vis}[GeV]");
  output_h->SetTitle("nonclosure m_{vis}");
  //output_h->SetXTitle("Z_{p}^{T}[GeV]");
  output_h->SetYTitle("Ratio");
  output_h->SetMaximum(2.);
  output_h->SetMinimum(0.);
  c2->SetName("nonclosure"+sample+"_c");
  c2->Write();
  TString SSstring="";
  if(CALC_SS_SR)SSstring+="_SS_SR";
  if ( doPlot)  c2->SaveAs("ViennaTool/Images/data_"+s_chan[CHAN]+"/nonclosure"+sample+SSstring+tight_cat+".png");
  //if ( doPlot)  c2->SaveAs("ViennaTool/Images/data_"+s_chan[CHAN]+"/nonclosure_zpt"+sample+SSstring+".png");

  FF_lookup.Close();output->Close();
  if( raw_ff.Contains("_fitted") ){
    for(int i=0; i<fittedFFs.size();i++){
      delete fittedFFs.at(i);
    }
  }
  
}

void FFCalculator::calc_nonclosure_lepPt(const Int_t mode, const TString raw_ff, const TString compare_file, const TString nonclosure_corr, const TString ff_output, const Int_t doPlot, const Int_t subtractMC, const Int_t tau_ind){

  cout << "Calculating corrections for " << ff_output << endl;
  Int_t nentries = Int_t(event_s->fChain->GetEntries());
  cout << nentries << endl;

  TString sample;
  if(mode & _QCD) sample="_QCD";
  if(mode & _W_JETS) sample="_Wjets";
  if(mode & _TT) sample="_TT";
  if(!subtractMC) sample+="_MC";
  
  TH1D *closure_h;
  Double_t FF_value=0;
  if(mode & _TT) closure_h= new TH1D("closure"+sample,"",nbins_lepPt,hist_min_lepPt,hist_max_lepPt);
  else closure_h= new TH1D("closure"+sample,"",nbins_lepPt,hist_min_lepPt,hist_max_lepPt);
  //TH1D *closure_h = new TH1D("closure"+sample,"",w_zpt_n,w_zpt_v);
  TFile *output = new TFile(ff_output,"RECREATE");
  TH1D *output_h = new TH1D("nonclosure_lepPt","",nbins_lepPt,hist_min_lepPt,hist_max_lepPt);
  //TH1D *output_h = new TH1D("nonclosure_zpt","",w_zpt_n,w_zpt_v);
  TFile FF_lookup(raw_ff);
  TH1D* FF_lookup_h = nullptr;
  if( !raw_ff.Contains("_fitted") ) FF_lookup_h = (TH1D*) FF_lookup.Get("c_t");
  vector<TGraphAsymmErrors*> fittedFFs;
  if( raw_ff.Contains("_fitted") ){
    TGraphAsymmErrors *dm0njet0 = (TGraphAsymmErrors*) FF_lookup.Get("dm0_njet0"); fittedFFs.push_back(dm0njet0);
    TGraphAsymmErrors *dm1njet0 = (TGraphAsymmErrors*) FF_lookup.Get("dm1_njet0"); fittedFFs.push_back(dm1njet0);
    TGraphAsymmErrors *dm0njet1 = (TGraphAsymmErrors*) FF_lookup.Get("dm0_njet1"); fittedFFs.push_back(dm0njet1);
    TGraphAsymmErrors *dm1njet1 = (TGraphAsymmErrors*) FF_lookup.Get("dm1_njet1"); fittedFFs.push_back(dm1njet1);
  }
  TFile nonclosure(nonclosure_corr);
  if(nonclosure.IsZombie()) cout << nonclosure_corr << " does not exist" << endl;
  TH1D* nonclosure_h = (TH1D*) nonclosure.Get("nonclosure_fit_smoothed");
  
  TFile compare(compare_file);
  if(subtractMC){
    TString ff_inputHist="hh_l"; 
    TH1D* compare_l              = (TH1D*) compare.Get(ff_inputHist+"_lepPt");
    TH1D* compare_l_MCsubtracted = (TH1D*) compare.Get(ff_inputHist+"_lepPt_MCsubtracted");
    //TH1D* compare_l              = (TH1D*) compare.Get("hh_l_zpt");
    //TH1D* compare_l_MCsubtracted = (TH1D*) compare.Get("hh_l_zpt_MCsubtracted");
    TH1D* ratio_l                = (TH1D*)compare_l_MCsubtracted->Clone("ratio_l");
    ratio_l->Divide(compare_l);
    ///get unity histogram
    TH1D *unity_h = new TH1D("unity","",nbins_lepPt,hist_min_lepPt,hist_max_lepPt);
    //TH1D *unity_h = new TH1D("unity","",w_zpt_n,w_zpt_v);
    for(int ibin=1; ibin<=unity_h->GetNbinsX(); ibin++) unity_h->SetBinContent(ibin,1.);
    ratio_l->Add(unity_h,-1);ratio_l->Scale(-1);
    TH1D* compare_t              = (TH1D*) compare.Get("hh_t_lepPt");
    TH1D* compare_t_MCsubtracted = (TH1D*) compare.Get("hh_t_lepPt_MCsubtracted");
    //TH1D* compare_t              = (TH1D*) compare.Get("hh_t_zpt");
    //TH1D* compare_t_MCsubtracted = (TH1D*) compare.Get("hh_t_zpt_MCsubtracted");

    //TFile nonclosure("fakefactor/data_mt/FF_corr_QCD_MCsum_noGen_nonclosure.root");
    //TH1D* nonclosure_h = (TH1D*) nonclosure.Get("nonclosure_smoothed");
    //TFile nonclosure_mt("fakefactor/data_mt/FF_corr_Wjets_MC_noGen_mtcorr.root");
    //TH1D* nonclosure_mt_h = (TH1D*) nonclosure_mt.Get("mt_corr_smoothed");
  
    for (Int_t jentry=0; jentry<nentries;jentry++) {
      event_s->GetEntry(jentry);
      if(jentry % 100000 == 0) cout << jentry << "/" << nentries << endl;
      if (mode & SR){
        if (  this->isInSR(mode,tau_ind) && this->isLoose(mode,tau_ind) ){
          if( !raw_ff.Contains("_fitted") ) FF_value = FF_lookup_h->GetBinContent( this->getBin(mode|tau_ind)+1 );
          else if( raw_ff.Contains("_fitted") ){
            FF_value = this->getFittedBinContent( mode, fittedFFs );
          }
          closure_h->Fill(event_s->lep_pt,FF_value*event_s->weight_sf*nonclosure_h->GetBinContent( this->getWeightIndex_mvis(event_s->alltau_mvis->at(tau_ind) )+1 ) );
        } 
      }
      else{
        if (  this->isInCR(mode,tau_ind) && this->isLoose(mode,tau_ind) ){
          if( !raw_ff.Contains("_fitted") ) FF_value = FF_lookup_h->GetBinContent( this->getBin(mode|tau_ind)+1 );
          else if( raw_ff.Contains("_fitted") ){
            FF_value = this->getFittedBinContent( mode, fittedFFs );
          }
          closure_h->Fill(event_s->lep_pt,FF_value*event_s->weight_sf*nonclosure_h->GetBinContent( this->getWeightIndex_mvis(event_s->alltau_mvis->at(tau_ind) )+1 ) );
        } 
      }
      /*if (mode & SR){
        if (  this->isInSR(mode,tau_ind) && this->isLoose(mode,tau_ind) ) closure_h->Fill(event_s->lep_pt,FF_lookup_h->GetBinContent( this->getBin(mode|tau_ind)+1 ) );
      }
      else{
        if (  this->isInCR(mode,tau_ind) && this->isLoose(mode,tau_ind) ) closure_h->Fill(event_s->lep_pt,FF_lookup_h->GetBinContent( this->getBin(mode|tau_ind)+1 ) );
        }*/
    }

    cout << "Here" << endl;
    closure_h->Multiply(ratio_l);
    output->cd();
    closure_h->Write();
  
    output_h = (TH1D*)compare_t->Clone("nonclosure");
    output_h->Add(compare_t_MCsubtracted,-1);
    compare_t->Add(compare_t_MCsubtracted,-1);
    compare_t->Write();
    output_h->Divide(closure_h);
  }
  else{ 
    TH1D* compare_t              = (TH1D*) compare.Get("hh_t_lepPt");
  
    for (Int_t jentry=0; jentry<nentries;jentry++) {
      event_s->GetEntry(jentry);
      if(jentry % 100000 == 0) cout << jentry << "/" << nentries << endl;
      if (mode & SR){
        if (  this->isInSR(mode,tau_ind) && this->isLoose(mode,tau_ind) ){
          if( !raw_ff.Contains("_fitted") ) FF_value = FF_lookup_h->GetBinContent( this->getBin(mode|tau_ind)+1 );
          else if( raw_ff.Contains("_fitted") ){
            FF_value = this->getFittedBinContent( mode, fittedFFs );
          }
          closure_h->Fill(event_s->lep_pt,FF_value*event_s->weight_sf );
        } 
      }
      else{
        if (  this->isInCR(mode,tau_ind) && this->isLoose(mode,tau_ind) ){
          if( !raw_ff.Contains("_fitted") ) FF_value = FF_lookup_h->GetBinContent( this->getBin(mode|tau_ind)+1 );
          else if( raw_ff.Contains("_fitted") ){
            FF_value = this->getFittedBinContent( mode, fittedFFs );
          }
          closure_h->Fill(event_s->lep_pt,FF_value*event_s->weight_sf );
        } 
      }
    }
    
    output->cd();
    closure_h->Write();
  
    output_h = (TH1D*)compare_t->Clone("nonclosure");
    output_h->Divide(closure_h);
  }

  TH1D* output_fit;
  /*if(CHAN==kTAU && calcVTightFF){
    output_fit=new TH1D("nonclosure_fit","",nbins_lepPt,hist_min_lepPt,hist_max_lepPt);
    for(int i=1;i<=output_h->GetNbinsX();i++){
      
      if( i >= 9 ){output_fit->SetBinContent(i,output_h->GetBinContent(i)); output_fit->SetBinError(i,output_h->GetBinError(i));}
    }
  }
  else*/ output_fit = (TH1D*)output_h->Clone("nonclosure_fit");

  for(int i=1;i<=output_h->GetNbinsX();i++){
    if( output_h->GetBinContent(i) < 0 ) output_h->SetBinError(i,1.);
  }
  
  output->cd();
  output_fit->Write();

  GaussianKernelSmoother gsk;
  int ret=gsk.setInputHisto( output_fit );
  if ( ret != 0 ) return;
  gsk.set_doWeights(1);
  gsk.set_doIgnoreZeroBins(0);
  gsk.set_kernelDistance( "lin" );
  gsk.set_doWidthInBins(1);
  gsk.set_doErrors(1);
  //if(mode & _QCD) gsk.set_lastBinFrom(150);
  Double_t fitWidth;
  if(mode & _QCD) fitWidth=2.; else if(mode & _W_JETS) fitWidth=2.; else fitWidth=2.;
  if(CHAN==kTAU) fitWidth=1.5;
  cout << "FitWidth: " << fitWidth << endl;
  gsk.setWidth(fitWidth);
  gsk.set_widthInBins_sf(1.115);
  //gsk.set_doWidthInBins(0);
  //gsk.setWidth(2*h->GetBinWidth(1));
  gsk.getSmoothHisto();
  TH1D *h2=gsk.returnSmoothedHisto();
  /*for(int i=1;i<=h2->GetNbinsX();i++){
    if(i<9){h2->SetBinContent(i,1);h2->SetBinError(i,0.1);}
    }*/
  h2->Write();

  gsk.set_doErrors(1);
  gsk.getContSmoothHisto();
  TGraphAsymmErrors *g=   gsk.returnSmoothedGraph();
  if(CHAN==kTAU){
    Double_t x_value; Double_t y_value; Double_t y_errorHigh; Double_t y_errorLow; Int_t counter;
    for(int i=0; i<g->GetN(); i++){
      g->GetPoint(i,x_value,y_value);
      if(x_value>=40){
        counter=i;
        y_errorHigh=g->GetErrorYhigh(i);
        y_errorLow=g->GetErrorYlow(i);
        break;
      }
    }
    for(int i=0; i<g->GetN(); i++){
      Double_t x; Double_t y; 
      g->GetPoint(i,x,y);
      if(x<40) {g->SetPoint(i,x,y_value); g->SetPointEYhigh(i,y_errorHigh); g->SetPointEYlow(i,y_errorLow);}
    }
  }

  Double_t xV; Double_t yV;
  g->GetPoint(375,xV,yV);
  for(int i=0; i<g->GetN(); i++){
    Double_t x; Double_t y;
    if(i>375){
      g->GetPoint(i,x,y);
      g->SetPoint(i,x,yV);
    }
  }

  ///////////////////////////////////////////////////////////////
  g->SetTitle("nonclosure"+sample);
  g->SetName("nonclosure"+sample);
  g->Write();

  TGraph *gup = (TGraphAsymmErrors*)g->Clone("nonclosure"+sample+"_up");
  gup->SetTitle("nonclosure"+sample+"_up");
  for(Int_t j=0;j<g->GetN();j++) gup->SetPoint(j,g->GetX()[j],g->GetErrorYhigh(j) );
  gup->Write();
  TGraph *gdown = (TGraphAsymmErrors*)g->Clone("nonclosure"+sample+"_down");
  gdown->SetTitle("nonclosure"+sample+"_down");
  for(Int_t j=0;j<g->GetN();j++) gdown->SetPoint(j,g->GetX()[j],g->GetErrorYlow(j) );
  gdown->Write();
  

  TCanvas *c2=new TCanvas();
  output_h->Draw("E");
  g->Draw("same LP");
  /*if(CHAN==kTAU && calcVTightFF){
    for(int i=1;i<=output_h->GetNbinsX();i++){
      if( i < 9 ){output_h->SetBinContent(i,0.); output_h->SetBinError(i,0.);}
    }
    }*/
  output_h->Draw("E same");
  output_h->SetXTitle("p_T [GeV]");
  output_h->SetTitle("nonclosure p_T");
  //output_h->SetXTitle("Z_{p}^{T}[GeV]");
  output_h->SetYTitle("Ratio");
  output_h->SetMaximum(2.);
  output_h->SetMinimum(0.);
  c2->SetName("nonclosure_pt"+sample+"_c");
  c2->Write();
  TString SSstring="";
  if(CALC_SS_SR)SSstring+="_SS_SR";
  if ( doPlot)  c2->SaveAs("ViennaTool/Images/data_"+s_chan[CHAN]+"/nonclosure_pt"+sample+SSstring+".png");
  //if ( doPlot)  c2->SaveAs("ViennaTool/Images/data_"+s_chan[CHAN]+"/nonclosure_zpt"+sample+SSstring+".png");

  FF_lookup.Close();output->Close();
  if( raw_ff.Contains("_fitted") ){
    for(int i=0; i<fittedFFs.size();i++){
      delete fittedFFs.at(i);
    }
  }
  
}

void FFCalculator::calc_muisocorr(const Int_t mode, const TString raw_ff, const TString CR_file, TString nonclosure_corr, TString ff_output, const TString tight_cat, const Int_t doPlot, const Int_t subtractMC, const Int_t tau_ind){

  cout << "Calculating corrections for " << ff_output << endl;
  Int_t nentries = Int_t(event_s->fChain->GetEntries());
  cout << nentries << endl;
  TFile *output = new TFile(ff_output.ReplaceAll(".root",tight_cat+".root"),"RECREATE");
  TH1D *output_h = new TH1D("muiso_corr","",w_muiso_n,w_muiso_v);
  TH1D *closure_h = new TH1D("closure","",w_muiso_n,w_muiso_v);
  TFile FF_lookup(raw_ff);
  if(FF_lookup.IsZombie()) cout << raw_ff << " does not exist" << endl;
  TH1D* FF_lookup_h = nullptr;
  if( !raw_ff.Contains("_fitted") ) FF_lookup_h = (TH1D*) FF_lookup.Get("c_t"+tight_cat);
  vector<TGraphAsymmErrors*> fittedFFs;
  if( raw_ff.Contains("_fitted") ){
    TGraphAsymmErrors *dm0njet0 = (TGraphAsymmErrors*) FF_lookup.Get("dm0_njet0"+tight_cat); fittedFFs.push_back(dm0njet0);
    TGraphAsymmErrors *dm1njet0 = (TGraphAsymmErrors*) FF_lookup.Get("dm1_njet0"+tight_cat); fittedFFs.push_back(dm1njet0);
    TGraphAsymmErrors *dm0njet1 = (TGraphAsymmErrors*) FF_lookup.Get("dm0_njet1"+tight_cat); fittedFFs.push_back(dm0njet1);
    TGraphAsymmErrors *dm1njet1 = (TGraphAsymmErrors*) FF_lookup.Get("dm1_njet1"+tight_cat); fittedFFs.push_back(dm1njet1);
  }
  TFile nonclosure(nonclosure_corr.ReplaceAll(".root",tight_cat+".root"));
  if(nonclosure.IsZombie()) cout << nonclosure_corr << " does not exist" << endl;
  TH1D* nonclosure_h = (TH1D*) nonclosure.Get("nonclosure_fit_smoothed");
  
  TFile compare(CR_file);
  Double_t FF_value=0;
  if(compare.IsZombie()) cout << CR_file << " does not exit" << endl;
  if(subtractMC){
    TH1D* compare_l              = (TH1D*) compare.Get("hh_l_muiso");
    TH1D* compare_l_MCsubtracted = (TH1D*) compare.Get("hh_l_muiso_MCsubtracted");
    TH1D* ratio_l                = (TH1D*)compare_l_MCsubtracted->Clone("ratio_l");
    ratio_l->Divide(compare_l);
    //get unity histogram
    TH1D *unity_h = new TH1D("unity","",w_muiso_n,w_muiso_v);
    for(int ibin=1; ibin<=unity_h->GetNbinsX(); ibin++) unity_h->SetBinContent(ibin,1.);
    ratio_l->Add(unity_h,-1);ratio_l->Scale(-1);
    TH1D* compare_t              = (TH1D*) compare.Get("hh_t"+tight_cat+"_muiso");
    TH1D* compare_t_MCsubtracted = (TH1D*) compare.Get("hh_t"+tight_cat+"_muiso_MCsubtracted");
    for (Int_t jentry=0; jentry<nentries;jentry++) {
      event_s->GetEntry(jentry);
      if(jentry % 100000 == 0) cout << jentry << "/" << nentries << endl;
      //if (  this->isInCR(mode,tau_ind) && this->isLoose(mode,tau_ind) ) closure_h->Fill(event_s->lep_iso,FF_lookup_h->GetBinContent( this->getBin(mode|tau_ind)+1 ) );
      if (  this->isInCR(mode,tau_ind) && this->isLoose(mode,tau_ind) ){
        if( !raw_ff.Contains("_fitted") ) FF_value = FF_lookup_h->GetBinContent( this->getBin(mode|tau_ind)+1 );
        else if( raw_ff.Contains("_fitted") ){
          FF_value = this->getFittedBinContent( mode, fittedFFs );
        }
        closure_h->Fill(event_s->lep_iso,event_s->weight_sf*FF_value*nonclosure_h->GetBinContent( this->getWeightIndex_mvis(event_s->alltau_mvis->at(tau_ind) )+1 ) );
      } 
    }
    
    closure_h->Multiply(ratio_l);
    output->cd();
    closure_h->Write();
  
    output_h = (TH1D*)compare_t->Clone("muiso_corr");
    output_h->Add(compare_t_MCsubtracted,-1);
    output_h->Divide(closure_h);
  }
  else{
    TH1D* compare_t              = (TH1D*) compare.Get("hh_t"+tight_cat+"_muiso");
    for (Int_t jentry=0; jentry<nentries;jentry++) {
      event_s->GetEntry(jentry);
      if(jentry % 100000 == 0) cout << jentry << "/" << nentries << endl;
      if (  this->isInCR(mode,tau_ind) && this->isLoose(mode,tau_ind) ){
        if( !raw_ff.Contains("_fitted") ) FF_value = FF_lookup_h->GetBinContent( this->getBin(mode|tau_ind)+1 );
        else if( raw_ff.Contains("_fitted") ){
          FF_value = this->getFittedBinContent( mode, fittedFFs );
        }
        closure_h->Fill(event_s->lep_iso,event_s->weight_sf*FF_value*nonclosure_h->GetBinContent( this->getWeightIndex_mvis(event_s->alltau_mvis->at(tau_ind) )+1 ) );
      } 
    }
    
    output->cd();
    closure_h->Write();
  
    output_h = (TH1D*)compare_t->Clone("muiso_corr");
    output_h->Divide(closure_h);
  }
    
  output->cd();
  output_h->Write();

  TString sample;
  if(mode & _QCD) sample="_QCD";
  if(mode & _W_JETS) sample="_Wjets";
  
  GaussianKernelSmoother gsk;
  int ret=gsk.setInputHisto( output_h );
  if ( ret != 0 ) return;
  gsk.set_doWeights(1);
  gsk.set_doIgnoreZeroBins(1);
  //gsk.set_kernelDistance( "err" );
  gsk.set_doWidthInBins(1);
  gsk.set_doErrors(1);
  Double_t fitWidth;
  if(!CALC_SS_SR) fitWidth=1.; else fitWidth=0.5;
  cout << "FitWidth: " << fitWidth << endl;
  gsk.setWidth(fitWidth);
  gsk.getSmoothHisto();
  TH1D *h2=gsk.returnSmoothedHisto();
  h2->Write();

  gsk.set_doErrors(1);
  gsk.getContSmoothHisto();
  TGraphAsymmErrors *g=   gsk.returnSmoothedGraph();
  g->SetTitle("muiso"+sample);
  g->SetName("muiso"+sample);
  g->Write();

  TGraph *gup = (TGraphAsymmErrors*)g->Clone("muiso_corr"+sample+"_up");
  gup->SetTitle("muiso_corr"+sample+"_up");
  for(Int_t j=0;j<g->GetN();j++) gup->SetPoint(j,g->GetX()[j],g->GetErrorYhigh(j) );
  gup->Write();
  TGraph *gdown = (TGraphAsymmErrors*)g->Clone("muiso_corr"+sample+"_down");
  gdown->SetTitle("muiso_corr"+sample+"_down");
  for(Int_t j=0;j<g->GetN();j++) gdown->SetPoint(j,g->GetX()[j],g->GetErrorYlow(j) );
  gdown->Write();
  

  TCanvas *c2=new TCanvas();
  output_h->Draw("E");
  g->Draw("same LP");
  output_h->Draw("E same");
  output_h->SetTitle("iso(#mu) correction");
  output_h->SetXTitle("iso(#mu)");
  output_h->SetYTitle("Ratio");
  output_h->SetMaximum(2.);
  output_h->SetMinimum(0.55);
  c2->SetName("muiso_corr"+sample+"_c");
  c2->Write();
  if(doPlot){
    if(!CALC_SS_SR) c2->SaveAs("ViennaTool/Images/data_"+s_chan[CHAN]+"/muisocorr"+sample+tight_cat+".png");
    if(CALC_SS_SR) c2->SaveAs("ViennaTool/Images/data_"+s_chan[CHAN]+"/muisocorr"+sample+tight_cat+"_SS_SR.png");
  }
  
  FF_lookup.Close();compare.Close();nonclosure.Close();output->Close();
  if( raw_ff.Contains("_fitted") ){
    for(int i=0; i<fittedFFs.size();i++){
      delete fittedFFs.at(i);
    }
  }
  
}

void FFCalculator::calc_OSSScorr(const Int_t mode, const TString raw_ff, const TString SR_file_AI, TString nonclosure_corr, TString ff_output, const TString tight_cat, const Int_t doPlot, const Int_t subtractMC, const Int_t tau_ind){

  cout << "Calculating corrections for " << ff_output << endl;
  Int_t nentries = Int_t(event_s->fChain->GetEntries());
  cout << nentries << endl;
  TFile *output = new TFile(ff_output.ReplaceAll(".root",tight_cat+".root"),"RECREATE");
  TH1D *output_h = new TH1D("OSSS_corr","",w_mvis_n,w_mvis_v);
  TH1D *closure_h = new TH1D("closure","",w_mvis_n,w_mvis_v);
  Double_t FF_value=0;
  TFile compare(SR_file_AI);
  if(compare.IsZombie()) cout << SR_file_AI << " does not exist" << endl;
  TFile FF_lookup(raw_ff);
  if(FF_lookup.IsZombie()) cout << raw_ff << " does not exist" << endl;
  TH1D* FF_lookup_h = nullptr;
  if( !raw_ff.Contains("_fitted") ) FF_lookup_h = (TH1D*) FF_lookup.Get("c_t"+tight_cat);
  vector<TGraphAsymmErrors*> fittedFFs;
  if( raw_ff.Contains("_fitted") ){
    TGraphAsymmErrors *dm0njet0 = (TGraphAsymmErrors*) FF_lookup.Get("dm0_njet0"+tight_cat); fittedFFs.push_back(dm0njet0);
    TGraphAsymmErrors *dm1njet0 = (TGraphAsymmErrors*) FF_lookup.Get("dm1_njet0"+tight_cat); fittedFFs.push_back(dm1njet0);
    TGraphAsymmErrors *dm0njet1 = (TGraphAsymmErrors*) FF_lookup.Get("dm0_njet1"+tight_cat); fittedFFs.push_back(dm0njet1);
    TGraphAsymmErrors *dm1njet1 = (TGraphAsymmErrors*) FF_lookup.Get("dm1_njet1"+tight_cat); fittedFFs.push_back(dm1njet1);
  }
  TFile nonclosure(nonclosure_corr.ReplaceAll(".root",tight_cat+".root"));
  if(nonclosure.IsZombie()) cout << nonclosure_corr << " does not exist" << endl;
  TH1D* nonclosure_h = (TH1D*) nonclosure.Get("nonclosure_fit_smoothed");

  if(subtractMC){
    TString ff_inputHist="hh_l";
    TH1D* compare_l              = (TH1D*) compare.Get(ff_inputHist+"_mvis");
    TH1D* compare_l_MCsubtracted = (TH1D*) compare.Get(ff_inputHist+"_mvis_MCsubtracted");
    TH1D* ratio_l                = (TH1D*)compare_l_MCsubtracted->Clone("ratio_l");
    ratio_l->Divide(compare_l);
    ///get unity histogram
    TH1D *unity_h = new TH1D("unity","",w_mvis_n,w_mvis_v);
    for(int ibin=1; ibin<=unity_h->GetNbinsX(); ibin++) unity_h->SetBinContent(ibin,1.);
    ratio_l->Add(unity_h,-1);ratio_l->Scale(-1);
    TH1D* compare_t              = (TH1D*) compare.Get("hh_t"+tight_cat+"_mvis");
    TH1D* compare_t_MCsubtracted = (TH1D*) compare.Get("hh_t"+tight_cat+"_mvis_MCsubtracted");
    //if(CHAN==kEL)compare_t_MCsubtracted->Scale(0.8);
    //if(CHAN==kMU)compare_t_MCsubtracted->Scale(0.95);
    TH1D* ratio_t                = (TH1D*)compare_t_MCsubtracted->Clone("ratio_t");
    ratio_t->Divide(compare_t);
    ratio_t->Add(unity_h,-1);ratio_t->Scale(-1);
    
    for (Int_t jentry=0; jentry<nentries;jentry++) {
      event_s->GetEntry(jentry);
      if(jentry % 100000 == 0) cout << jentry << "/" << nentries << endl;
      if (  this->isInSR(mode,tau_ind) && this->isLoose(mode,tau_ind) ){
        if( !raw_ff.Contains("_fitted") ) FF_value = FF_lookup_h->GetBinContent( this->getBin(mode|tau_ind)+1 );
        else if( raw_ff.Contains("_fitted") ){
          FF_value = this->getFittedBinContent( mode, fittedFFs );
        }
        closure_h->Fill(event_s->alltau_mvis->at(tau_ind),event_s->weight_sf*FF_value*nonclosure_h->GetBinContent( this->getWeightIndex_mvis(event_s->alltau_mvis->at(tau_ind) )+1 ) );
      } 
    }
    
    closure_h->Multiply(ratio_l);
    output->cd();
    ratio_l->Write();
    ratio_t->Write();
    closure_h->Write();
    
    output_h = (TH1D*)compare_t->Clone("OSSS_corr");
    output_h->Add(compare_t_MCsubtracted,-1);
    output_h->Divide(closure_h);
    
    for(int i=1;i<=output_h->GetNbinsX();i++){
      if( output_h->GetBinContent(i) < 0 ) output_h->SetBinError(i,1.);
    }
  }
  else{
    TH1D* compare_t              = (TH1D*) compare.Get("hh_t"+tight_cat+"_mvis");
    for (Int_t jentry=0; jentry<nentries;jentry++) {
      event_s->GetEntry(jentry);
      if(jentry % 100000 == 0) cout << jentry << "/" << nentries << endl;
      if (  this->isInSR(mode,tau_ind) && this->isLoose(mode,tau_ind) ){
        if( !raw_ff.Contains("_fitted") ) FF_value = FF_lookup_h->GetBinContent( this->getBin(mode|tau_ind)+1 );
        else if( raw_ff.Contains("_fitted") ){
          FF_value = this->getFittedBinContent( mode, fittedFFs );
        }
        closure_h->Fill(event_s->alltau_mvis->at(tau_ind),event_s->weight_sf*FF_value*nonclosure_h->GetBinContent( this->getWeightIndex_mvis(event_s->alltau_mvis->at(tau_ind) )+1 )/**muiso_h->GetBinContent( this->getWeightIndex_muiso(event_s->lep_iso)+1 )*/ );
      } 
    }
    
    output->cd();
    closure_h->Write();
  
    output_h = (TH1D*)compare_t->Clone("OSSS_corr");
    output_h->Divide(closure_h);

    /*for(int i=0; i<output_h->GetNbinsX(); i++){
      if(i>10) output_h->SetBinContent(i,1.);
      if(i>10) output_h->SetBinError(i,0.1);
      }*/
  }
  
  output->cd();
  output_h->Write();

  TString sample;
  if(mode & _QCD) sample="_QCD";
  if(mode & _W_JETS) sample="_Wjets";
  
  GaussianKernelSmoother gsk;
  int ret=gsk.setInputHisto( output_h );
  if ( ret != 0 ) return;
  gsk.set_doWeights(1);
  gsk.set_doIgnoreZeroBins(1);
  gsk.set_kernelDistance( "lin" );
  gsk.set_doWidthInBins(1);
  gsk.set_doErrors(1);
  gsk.setWidth( 2. );
  if(CHAN ==kTAU ) gsk.setWidth(1.5);
  gsk.set_widthInBins_sf(1.115);
  //if(mode & _QCD) gsk.set_lastBinFrom(170);
  gsk.getSmoothHisto();
  TH1D *h2=gsk.returnSmoothedHisto();
  h2->Write();

  gsk.set_doErrors(1);
  gsk.getContSmoothHisto();
  TGraphAsymmErrors *g=   gsk.returnSmoothedGraph();
  if(CHAN==kTAU){
    Double_t x_value; Double_t y_value; Double_t y_errorHigh; Double_t y_errorLow; Int_t counter;
    for(int i=0; i<g->GetN(); i++){
      g->GetPoint(i,x_value,y_value);
      if(x_value>=80){
        counter=i;
        y_errorHigh=g->GetErrorYhigh(i);
        y_errorLow=g->GetErrorYlow(i);
        break;
      }
    }
    for(int i=0; i<g->GetN(); i++){
      Double_t x; Double_t y; 
      g->GetPoint(i,x,y);
      //if(x<80) {g->SetPoint(i,x,y_value); g->SetPointEYhigh(i,y_errorHigh); g->SetPointEYlow(i,y_errorLow);}
    }
  }
  Double_t x200; Double_t y200;
  if(CHAN==kMU)g->GetPoint(180,x200,y200);
  if(CHAN==kEL)g->GetPoint(110,x200,y200);
  for(int i=0; i<g->GetN(); i++){
    Double_t x; Double_t y;
    if(CHAN==kMU && i>180){
      g->GetPoint(i,x,y);
      g->SetPoint(i,x,y200);
    }
    else if(CHAN==kEL && i>110){
      g->GetPoint(i,x,y);
      g->SetPoint(i,x,y200);
    }
  }

  ///////////////////////////////////////////////////////////////
  /*int ilimit=0;
  Double_t limitValueHigh=0;
  Double_t limitValueLow=0;
  for(int i=0; i<g->GetN(); i++){
    Double_t x; Double_t y;
    g->GetPoint(i,x,y);
    if(x>=100 && ilimit==0) {
      limitValueHigh=g->GetErrorYhigh(i)/y;
      limitValueLow=g->GetErrorYlow(i)/y;
      //cout << y << " " << g->GetErrorYhigh(i) << " " << limitValueHigh << endl;
      ilimit=i;
    }
  }
  for(int i=0; i<g->GetN(); i++){
    Double_t x; Double_t y;
    g->GetPoint(i,x,y);
    if(x>100) {
      g->SetPointEYhigh(i,g->GetErrorYhigh(i)+(i-ilimit)*(limitValueHigh/50) );
      g->SetPointEYlow(i,g->GetErrorYlow(i)+(i-ilimit)*(limitValueLow/50) );
    }
    }*/
  ///////////////////////////////////////////////////////////////
  
  g->SetTitle("OSSS_corr"+sample);
  g->SetName("OSSS_corr"+sample);
  g->Write();

  TGraph *gup = (TGraphAsymmErrors*)g->Clone("OSSS_corr"+sample+"_up");
  gup->SetTitle("OSSS_corr"+sample+"_up");
  for(Int_t j=0;j<g->GetN();j++) gup->SetPoint(j,g->GetX()[j],g->GetErrorYhigh(j) );
  gup->Write();
  TGraph *gdown = (TGraphAsymmErrors*)g->Clone("OSSS_corr"+sample+"_down");
  gdown->SetTitle("OSSS_corr"+sample+"_down");
  for(Int_t j=0;j<g->GetN();j++) gdown->SetPoint(j,g->GetX()[j],g->GetErrorYlow(j) );
  gdown->Write();
  

  TCanvas *c2=new TCanvas();
  output_h->Draw("E");
  g->Draw("same LP");
  output_h->Draw("E same");
  output_h->SetTitle("OS/SS ratio");
  output_h->SetXTitle("m_{vis}[GeV]");
  output_h->SetYTitle("Ratio");
  output_h->SetMaximum(2.);
  output_h->SetMinimum(0.);
  c2->SetName("OSSS_corr"+sample+"_c");
  c2->Write();
  if(doPlot)c2->SaveAs("ViennaTool/Images/data_"+s_chan[CHAN]+"/OSSScorr"+sample+tight_cat+".png");

  FF_lookup.Close();compare.Close();nonclosure.Close();output->Close();
  if( raw_ff.Contains("_fitted") ){
    for(int i=0; i<fittedFFs.size();i++){
      delete fittedFFs.at(i);
    }
  }
}


void FFCalculator::calc_mtcorr(const Int_t mode, const TString raw_ff, const TString CR_file, TString nonclosure_corr, TString ff_output, const TString tight_cat, const Int_t tau_ind){

  cout << "Calculating corrections for " << ff_output << endl;
  Int_t nentries = Int_t(event_s->fChain->GetEntries());
  cout << nentries << endl;
  TFile *output = new TFile(ff_output.ReplaceAll(".root",tight_cat+".root"),"RECREATE");

  TH1D *output_h = new TH1D("mt_corr","",w_mt_n,w_mt_v);
  TH1D *closure_h = new TH1D("closure","",w_mt_n,w_mt_v);
  Double_t FF_value=0;
  TFile compare(CR_file);
  TH1D* compare_t              = (TH1D*) compare.Get("hh_t"+tight_cat+"_mt");
  TFile FF_lookup(raw_ff);
  TH1D* FF_lookup_h = nullptr;
  if( !raw_ff.Contains("_fitted") ) FF_lookup_h = (TH1D*) FF_lookup.Get("c_t"+tight_cat);
  vector<TGraphAsymmErrors*> fittedFFs;
  if( raw_ff.Contains("_fitted") ){
    TGraphAsymmErrors *dm0njet0 = (TGraphAsymmErrors*) FF_lookup.Get("dm0_njet0"+tight_cat); fittedFFs.push_back(dm0njet0);
    TGraphAsymmErrors *dm1njet0 = (TGraphAsymmErrors*) FF_lookup.Get("dm1_njet0"+tight_cat); fittedFFs.push_back(dm1njet0);
    TGraphAsymmErrors *dm0njet1 = (TGraphAsymmErrors*) FF_lookup.Get("dm0_njet1"+tight_cat); fittedFFs.push_back(dm0njet1);
    TGraphAsymmErrors *dm1njet1 = (TGraphAsymmErrors*) FF_lookup.Get("dm1_njet1"+tight_cat); fittedFFs.push_back(dm1njet1);
  }
  TFile nonclosure(nonclosure_corr);
  TH1D* nonclosure_h = (TH1D*) nonclosure.Get("nonclosure_fit_smoothed");
  for (Int_t jentry=0; jentry<nentries;jentry++) {
      event_s->GetEntry(jentry);
      if(jentry % 100000 == 0) cout << jentry << "/" << nentries << endl;
      //if (  this->isInCR(mode,tau_ind) && this->isLoose(mode,tau_ind) ) closure_h->Fill(event_s->lep_iso,FF_lookup_h->GetBinContent( this->getBin(mode|tau_ind)+1 ) );
      if (  this->isInSR(mode,tau_ind) && this->isLoose(mode,tau_ind) ){
        if( !raw_ff.Contains("_fitted") ) FF_value = FF_lookup_h->GetBinContent( this->getBin(mode|tau_ind)+1 );
        else if( raw_ff.Contains("_fitted") ){
          FF_value = this->getFittedBinContent( mode, fittedFFs );
        }
        closure_h->Fill(event_s->alltau_mt->at(tau_ind),FF_value*nonclosure_h->GetBinContent( this->getWeightIndex_mvis(event_s->alltau_mvis->at(tau_ind) )+1 )*event_s->weight_sf );
      }
  }

  output->cd();
  closure_h->Write();
  
  output_h = (TH1D*)compare_t->Clone("mt_corr");
  output_h->Divide(closure_h);
  
  output->cd();
  output_h->Write();

  TString sample;
  if(mode & _QCD) sample="_QCD";
  if(mode & _W_JETS) sample="_Wjets";
  GaussianKernelSmoother gsk;
  int ret=gsk.setInputHisto( output_h );
  if ( ret != 0 ) return;
  gsk.set_doWeights(1);
  gsk.set_doIgnoreZeroBins(1);
  gsk.set_kernelDistance( "lin" );
  gsk.set_doWidthInBins(1);
  gsk.setWidth(1.);
  Double_t lastBin;
  if(CHAN==kMU) lastBin=150;
  if(CHAN==kEL) lastBin=150;
  gsk.set_lastBinFrom(lastBin);
  gsk.getSmoothHisto();
  TH1D *h2=gsk.returnSmoothedHisto();
  h2->Write();

  gsk.set_doErrors(1);
  gsk.getContSmoothHisto();
  TGraphAsymmErrors *g=   gsk.returnSmoothedGraph();
  g->SetTitle("mt_corr"+sample);
  g->SetName("mt_corr"+sample);
  g->Write();

  TGraph *gup = (TGraphAsymmErrors*)g->Clone("mt_corr"+sample+"_up");
  gup->SetTitle("mt_corr"+sample+"_up");
  for(Int_t j=0;j<g->GetN();j++) gup->SetPoint(j,g->GetX()[j],g->GetErrorYhigh(j) );
  gup->Write();
  TGraph *gdown = (TGraphAsymmErrors*)g->Clone("mt_corr"+sample+"_down");
  gdown->SetTitle("mt_corr"+sample+"_down");
  for(Int_t j=0;j<g->GetN();j++) gdown->SetPoint(j,g->GetX()[j],g->GetErrorYlow(j) );
  gdown->Write();
  
  TCanvas *c2=new TCanvas();
  output_h->Draw("E");
  g->Draw("same LP");
  output_h->Draw("E same");
  output_h->SetTitle("m_{T} correction");
  output_h->SetXTitle("m_{T}[GeV]");
  output_h->SetYTitle("Ratio");
  output_h->SetMaximum(2.);
  output_h->SetMinimum(0.);
  c2->SetName("mt_corr"+sample+"_c");
  c2->Write();
  if(!CALC_SS_SR) c2->SaveAs("ViennaTool/Images/data_"+s_chan[CHAN]+"/mtcorr"+sample+tight_cat+".png");
  if(CALC_SS_SR) c2->SaveAs("ViennaTool/Images/data_"+s_chan[CHAN]+"/mtcorr"+sample+tight_cat+"_SS_SR.png");

  FF_lookup.Close();compare.Close();output->Close();
  if( raw_ff.Contains("_fitted") ){
    for(int i=0; i<fittedFFs.size();i++){
      delete fittedFFs.at(i);
    }
  }
}

Double_t FFCalculator::return_yvalue(Double_t xvalue, TGraphAsymmErrors* g){

  Int_t j=0;
  for (j=0;j<g->GetN();j++) {
    if (TMath::AreEqualRel(xvalue,g->GetX()[j],5e-4)) {
      //printf("found point %d with x=%g, y=%g\n",j,g->GetX()[j],g->GetY()[j]);
      return g->GetY()[j];
    }
  }
  for (j=0;j<g->GetN();j++) {
    if (TMath::AreEqualRel(xvalue,g->GetX()[j],5e-3)) {
      //printf("found point %d with x=%g, y=%g\n",j,g->GetX()[j],g->GetY()[j]);
      return g->GetY()[j];
    }
  }
  for (j=0;j<g->GetN();j++) {
    if (TMath::AreEqualRel(xvalue,g->GetX()[j],5e-2)) {
      //printf("found point %d with x=%g, y=%g\n",j,g->GetX()[j],g->GetY()[j]);
      return g->GetY()[j];
    }
  }
  for (j=0;j<g->GetN();j++) {
    if (TMath::AreEqualRel(xvalue,g->GetX()[j],5e-1)) {
      //printf("found point %d with x=%g, y=%g\n",j,g->GetX()[j],g->GetY()[j]);
      return g->GetY()[j];
    }
  }
  return 1.;
  
}

void FFCalculator::subtractBackground(TH1D* fakefactor_histo, TString fname, const Int_t mode, const Int_t categoryMode, Int_t cuts, Int_t tau_ind){

  vector<TString> restNames;
  restNames.push_back(preselection_DY_TT); restNames.push_back(preselection_DY_L); restNames.push_back(preselection_TT_T); restNames.push_back(preselection_TT_L);
  if(useVV) restNames.push_back(preselection_VV_T); restNames.push_back(preselection_VV_L);


  TFile* ff_file;
  ff_file = TFile::Open(fname);
  FakeFactor* ff    = (FakeFactor*)ff_file->Get("ff_comb");
  vector<Double_t> inputs;
  
  
  TString histname="background";
  TH1D* background; 
  if( mode & MVIS) {background = new TH1D(histname,"",nbins_mvis,hist_min_mvis,hist_max_mvis);}
  else if( mode & MT) {background = new TH1D(histname,"",nbins_mt,hist_min_mt,hist_max_mt);}
  else if( mode & PT) {background = new TH1D(histname,"",nbins_pt,hist_min_pt,hist_max_pt);}
  else if( mode & SVFIT) {background = new TH1D(histname,"",nbins_svfit,hist_min_svfit,hist_max_svfit);}
  else if( mode & M2T) {background = new TH1D(histname,"",nbins_mt2,hist_min_mt2,hist_max_mt2);}
  else if( mode & MVAMET) {background = new TH1D(histname,"",nbins_mvamet,hist_min_mvamet,hist_max_mvamet);}
  else if( mode & MET) {background = new TH1D(histname,"",nbins_met,hist_min_met,hist_max_met);}
  else if( mode & LEPPT) {background = new TH1D(histname,"",nbins_lepPt,hist_min_lepPt,hist_max_lepPt);}
  else if( mode & ETA) {background = new TH1D(histname,"",nbins_eta,hist_min_eta,hist_max_eta);}
  else if( mode & MMTOT) {background = new TH1D(histname,"",nbins_mttot,hist_min_mttot,hist_max_mttot);}
  else{
    cout << "Error: Wrong mode specified in FFCalculator::getSystUncertainties" << endl;
    exit(0);
  }

  for (unsigned i=0; i<restNames.size(); i++){

    Double_t fillVal;
    loadFile(restNames.at(i),"Events");
    Int_t nentries=Int_t(event_s->fChain->GetEntries());
    cout << "Subtracting non fake background in SR for " <<  restNames.at(i) << " with " << nentries << " events." << endl;

    for (Int_t jentry=0; jentry<nentries;jentry++) {
      event_s->GetEntry(jentry);
      if (   this->isInSR(mode,tau_ind) && this->isLoose(mode,tau_ind)  && ( !cuts || this->passesCuts(cuts,tau_ind) )  ) { //!cuts for performance
        if ( !fulfillCategory(categoryMode) ) continue;
        fillVal=this->selVal(mode,tau_ind);
        inputs.clear();
        this->getInputs(inputs, tau_ind);
        double ffvalue;
        ffvalue = ffvalue = ff->value(inputs);
        background->Fill(fillVal, event_s->weight_sf*ffvalue);
      }
    }
    cout << background->Integral() << endl;
  }

  
  fakefactor_histo->Add(background,-1);
  
  delete background; delete ff;
  ff_file->Close();
  
  
}

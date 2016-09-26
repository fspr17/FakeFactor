#include "Settings.h"
#include "TString.h"

#define _W_JETS         1
#define _DY             2
#define _TT             4
#define _QCD            8
#define _DY_TT         16
#define _DY_J          32
#define _DY_L          64
#define _TT_T         128
#define _TT_J         256
#define _TT_L         512
#define SR           1024
#define NO_SR        2048
#define DOALL        4096
#define GEN_MATCH    8192
#define VSVAR       16384
#define MT          32768
#define MVIS        65536
#define PT         131072
#define ETA        262144
#define MTLL       524288
#define MUISO     1048576
#define NB        2097152
#define DRB       4194304
#define _WCORR    8388608
#define _TTCORR  16777216
#define _FIT     33554432
#define _SS      67108864
#define _AI     134217728
#define _QCDISO 268435456
#define _VV     536870912
#define ZPT     1073741824
#define NJETS   2147483648

//#define NBJETS  2147483648
//int max:     4294967295

#define _VV_T        1
#define _VV_J        2
#define _VV_L        4

//#define _SS_AI       1
//#define _OS_AI       2

#define NP1          1
#define NP3          2
#define PT1          4
#define PT2          8
#define PT3         16
#define ETA1        32
#define ETA2        64
#define ETA3       128

#define _COLOR          1
#define _COLOR_RUN1     2
#define _COLOR_FF       4
#define _COLOR_CHECK    8
#define _COMPARE       16
#define _COMPARE2      32

//be very careful to not overlap with other marks -> use category mark extra
#define _INCL         1
#define _0JET         2
#define _1JET         4
#define _1JETZ050     8
#define _1JETZ50100  16
#define _1JETZ100    32
#define _2JET        64
#define _2JETVBF    128
#define _ANYB       256

#define _INCLFRAC_MT     1024
#define _CATFRAC_MT      2048
#define _INCLFRAC_ET     4096
#define _CATFRAC_ET      8192
#define _INCLFRAC_TT    16384
#define _CATFRAC_TT     32768

const Int_t promptE   =1;
const Int_t promptMu  =2;
const Int_t tauE      =3;
const Int_t tauMu     =4;
const Int_t tauH      =5;
const Int_t realJet   =6;


const TString curr_svfit[] = { "woSVFIT", "SVFIT"};
const TString s_chan[]     = {"mt", "et", "tt"};

const TString s_preselection ="preselection";
const TString s_weighted     ="weighted";
const TString s_SR           ="SR";
const TString s_SS_SR        ="SS_SR";
const TString s_CR           ="CR";
const TString s_MC           ="MC";
const TString s_MCsum        ="MCsum";
const TString s_corr         ="corr";
const TString s_mt           ="mt";
const TString s_mtll         ="mtll";
const TString s_nb           ="nb";
const TString s_drb          ="drb";
const TString s_mvis         ="mvis";
const TString s_pt           ="pt";
const TString s_muiso        ="muiso";
const TString s_Wjets        ="Wjets";
const TString s_QCD          ="QCD";
const TString s_TT           ="TT";
const TString s_TT_J         ="TT_J";
const TString s_TT_T         ="TT_T";
const TString s_TT_L         ="TT_L";
const TString s_DY           ="DY";
const TString s_DY_J         ="DY_J";
const TString s_DY_TT        ="DY_TT";
const TString s_DY_L         ="DY_L";
const TString s_loose        ="loose";
const TString s_loose_tt     ="loose_tt";
const TString s_tight        ="tight";


//FF file produced by official tools
const TString FF_inputFile=inputFF_dir+inputFF_date+"/XXXXX/fakeFactors_"+inputFF_date+".root";

//Output directories
const TString path_presel        = "/data/"+user+"/"+analysis+"/preselection/"+s_chan[CHAN]+"/";
const TString path_ff            = "ViennaTool/fakefactor/";
const TString path_ff_data       = path_ff+"data_"+s_chan[CHAN]+"/";
const TString path_ff_mc         = path_ff+"mc_"+s_chan[CHAN]+"/";
const TString path_ff_mc_woQCD   = path_ff+"mc_woQCD_"+s_chan[CHAN]+"/";
const TString path_sim           = "ViennaTool/sim/"+s_chan[CHAN]+"/";
const TString path_img           = "ViennaTool/Images/";
const TString path_img_data      = path_img+"data_"+s_chan[CHAN]+"/";
const TString path_img_mc        = path_img+"mc_"+s_chan[CHAN]+"/";
const TString path_img_mc_woQCD  = path_img+"mc_woQCD_"+s_chan[CHAN]+"/";

//Input directories
const TString indir = "/data/higgs/data_2015/ntuples_"+ver+"/"+s_chan[CHAN]+"/ntuples_"+curr_svfit[use_svfit]+"_merged/";

const TString datafiles[3] = { indir + "BASIS_ntuple_SingleMuon_16Dec_mt_"+ver+".root" , indir + "BASIS_ntuple_SingleElectron_16Dec_et_"+ver+".root" , indir + "BASIS_ntuple_Tau_16Dec_tt_"+ver+".root" };
const TString datafile   = datafiles[CHAN];

const TString DY_NJfile  = indir + "BASIS_ntuple_DYXJetsToLL_lowMass_merged_MCFall15_"+s_chan[CHAN]+"_"+ver+".root";
const TString DYfile     = DY_NJfile;
const TString Wjetsfile  = indir + "BASIS_ntuple_WXJets_merged_MCFall15_"+s_chan[CHAN]+"_"+ver+".root";
const TString QCDfile    = indir + "BASIS_ntuple_QCD_Pt20toInf_MuEnrichedPt15_MCFall15_"+s_chan[CHAN]+"_"+ver+".root";
const TString VVfile     = indir + "BASIS_ntuple_VV_MCFall15_"+s_chan[CHAN]+"_"+ver+".root";
const TString TTfile     = indir + "BASIS_ntuple_TT_MCFall15_"+s_chan[CHAN]+"_"+ver+".root";


// Preselection files
const TString preselection_data          = path_presel+"preselection_data.root";
const TString preselection_Wjets         = path_presel+"preselection_Wjets.root";
const TString preselection_DY            = path_presel+"preselection_DY.root";
const TString preselection_DY_TT         = path_presel+"preselection_DY_TT.root";
const TString preselection_DY_J          = path_presel+"preselection_DY_J.root";
const TString preselection_DY_L          = path_presel+"preselection_DY_L.root";
const TString preselection_TT            = path_presel+"preselection_TT.root";
const TString preselection_TT_T          = path_presel+"preselection_TT_T.root";
const TString preselection_TT_J          = path_presel+"preselection_TT_J.root";
const TString preselection_TT_L          = path_presel+"preselection_TT_L.root";
const TString preselection_VV            = path_presel+"preselection_VV.root";
const TString preselection_VV_T          = path_presel+"preselection_VV_T.root";
const TString preselection_VV_J          = path_presel+"preselection_VV_J.root";
const TString preselection_VV_L          = path_presel+"preselection_VV_L.root";
const TString preselection_MCsum         = path_presel+"preselection_"+s_MCsum+".root";
const TString preselection_MCsum_woQCD   = path_presel+"preselection_"+s_MCsum+"_woQCD.root";
const TString preselection_QCD           = path_presel+"preselection_QCD.root";
const TString preselection_QCD_Pt        = path_presel+"preselection_QCD_Pt.root";

const TString fit_formula                = "fit_formula.root";

// Fakefactor weight files
const TString weight_Wjets = "weight_Wjets.root";
const TString weight_DY_J = "weight_DY_J.root";
const TString weight_TT_J = "weight_TT_J.root";
const TString weight_QCD   = "weight_QCD.root";
const TString weight_sum   = "weight_sum.root";
const TString a_weight[4]={weight_Wjets, weight_DY_J, weight_TT_J, weight_QCD};
const TString template_file_name = "templates.root";

// Fake factor files (single MC file)
const TString FF_Wjets_only                  = "FF_Wjets_only.root";
const TString FF_DY_J_only                   = "FF_DY_J_only.root";
const TString FF_TT_J_only                   = "FF_TT_J_only.root";
const TString FF_QCD_only                    = "FF_QCD_only.root";

const TString FF_Wjets_only_SR               = "FF_Wjets_only_"+s_SR+".root";
const TString FF_DY_J_only_SR                = "FF_DY_J_only_"+s_SR+".root";
const TString FF_TT_J_only_SR                = "FF_TT_J_only_"+s_SR+".root";
const TString FF_QCD_only_SR                 = "FF_QCD_only_"+s_SR+".root";
const TString FF_QCD_only_SS                 = "FF_QCD_only_SS.root";
const TString FF_QCD_only_iso                 = "FF_QCD_only_iso.root";
const TString FF_QCD_only_mvis_SS                 = "FF_QCD_only_mvis_SS.root";
const TString FF_QCD_only_mvis_iso                 = "FF_QCD_only_mvis_iso.root";


// Fake factor files (vs mt)
const TString FF_Wjets_only_mt                  = "FF_Wjets_only_"+s_mt+".root";
const TString FF_DY_J_only_mt                   = "FF_DY_J_only_"+s_mt+".root";
const TString FF_TT_J_only_mt                   = "FF_TT_J_only_"+s_mt+".root";
const TString FF_QCD_only_mt                    = "FF_QCD_only_"+s_mt+".root";

const TString FF_Wjets_only_mt_SR               = "FF_Wjets_only_"+s_mt+"_"+s_SR+".root";
const TString FF_DY_J_only_mt_SR                = "FF_DY_J_only_"+s_mt+"_"+s_SR+".root";
const TString FF_TT_J_only_mt_SR                = "FF_TT_J_only_"+s_mt+"_"+s_SR+".root";
const TString FF_QCD_only_mt_SR                 = "FF_QCD_only_"+s_mt+"_"+s_SR+".root";

const TString FF_Wjets_only_mt_CR               = "FF_Wjets_only_"+s_mt+"_"+s_CR+".root";
const TString FF_DY_J_only_mt_CR                = "FF_DY_J_only_"+s_mt+"_"+s_CR+".root";
const TString FF_TT_J_only_mt_CR                = "FF_TT_J_only_"+s_mt+"_"+s_CR+".root";
const TString FF_QCD_only_mt_CR                 = "FF_QCD_only_"+s_mt+"_"+s_CR+".root";

const TString FF_Wjets_only_mt_fit              = "FF_Wjets_only_"+s_mt+"_fit.root";
const TString FF_Wjets_only_mt_1p_fit           = "FF_Wjets_only_"+s_mt+"_1p_fit.root";
const TString FF_Wjets_only_mt_3p_fit           = "FF_Wjets_only_"+s_mt+"_3p_fit.root";

//Fake factor files (vs mvis)
const TString FF_QCD_only_mvis                    = "FF_QCD_only_"+s_mvis+".root";

const TString FF_QCD_only_mvis_SR                 = "FF_QCD_only_"+s_mvis+"_"+s_SR+".root";

// Fake factor files (vs mtll)
const TString FF_Wjets_only_mtll                  = "FF_Wjets_only_"+s_mtll+".root";
const TString FF_DY_J_only_mtll                   = "FF_DY_J_only_"+s_mtll+".root";
const TString FF_TT_J_only_mtll                   = "FF_TT_J_only_"+s_mtll+".root";
const TString FF_QCD_only_mtll                    = "FF_QCD_only_"+s_mtll+".root";

const TString FF_Wjets_only_mtll_SR               = "FF_Wjets_only_"+s_mtll+"_"+s_SR+".root";
const TString FF_DY_J_only_mtll_SR                = "FF_DY_J_only_"+s_mtll+"_"+s_SR+".root";
const TString FF_TT_J_only_mtll_SR                = "FF_TT_J_only_"+s_mtll+"_"+s_SR+".root";
const TString FF_QCD_only_mtll_SR                 = "FF_QCD_only_"+s_mtll+"_"+s_SR+".root";

const TString FF_Wjets_only_mtll_CR               = "FF_Wjets_only_"+s_mtll+"_"+s_CR+".root";
const TString FF_DY_J_only_mtll_CR                = "FF_DY_J_only_"+s_mtll+"_"+s_CR+".root";
const TString FF_TT_J_only_mtll_CR                = "FF_TT_J_only_"+s_mtll+"_"+s_CR+".root";
const TString FF_QCD_only_mtll_CR                 = "FF_QCD_only_"+s_mtll+"_"+s_CR+".root";

const TString FF_QCD_only_muiso                   = "FF_QCD_only_"+s_muiso+".root";
const TString FF_QCD_only_muiso_CR                = "FF_QCD_only_"+s_muiso+"_"+s_CR+".root";
const TString FF_QCD_only_muiso_SR                = "FF_QCD_only_"+s_muiso+"_"+s_SR+".root";
const TString FF_corr_QCD_MCsum_muiso             = "FF_"+s_corr+"_QCD_"+s_MCsum+"_noGen_"+s_muiso+".root";
const TString FF_corr_QCD_MCsum_muiso_CR          = "FF_"+s_corr+"_QCD_"+s_MCsum+"_noGen_"+s_muiso+"_"+s_CR+".root";
const TString FF_corr_QCD_MCsum_muiso_SR          = "FF_"+s_corr+"_QCD_"+s_MCsum+"_noGen_"+s_muiso+"_"+s_SR+".root";

const TString FF_QCD_only_nb_CR                   = "FF_QCD_only_"+s_nb+"_"+s_CR+".root";
const TString FF_QCD_only_nb_SR                   = "FF_QCD_only_"+s_nb+"_"+s_SR+".root";
const TString FF_TT_J_only_nb_CR                  = "FF_TT_J_only_"+s_nb+"_"+s_CR+".root";
const TString FF_TT_J_only_nb_SR                  = "FF_TT_J_only_"+s_nb+"_"+s_SR+".root";
const TString FF_corr_QCD_MCsum_nb_CR             = "FF_"+s_corr+"_QCD_" +s_MCsum+"_noGen_"+s_nb+"_"+s_CR+".root";
const TString FF_corr_TT_J_MCsum_nb_CR            = "FF_"+s_corr+"_TT_J_"+s_MCsum+"_noGen_"+s_nb+"_"+s_CR+".root";

const TString FF_QCD_only_drb_CR                   = "FF_QCD_only_"+s_drb+"_"+s_CR+".root";
const TString FF_QCD_only_drb_SR                   = "FF_QCD_only_"+s_drb+"_"+s_SR+".root";
const TString FF_TT_J_only_drb_CR                  = "FF_TT_J_only_"+s_drb+"_"+s_CR+".root";
const TString FF_TT_J_only_drb_SR                  = "FF_TT_J_only_"+s_drb+"_"+s_SR+".root";
const TString FF_corr_QCD_MCsum_drb_CR             = "FF_"+s_corr+"_QCD_" +s_MCsum+"_noGen_"+s_drb+"_"+s_CR+".root";
const TString FF_corr_TT_J_MCsum_drb_CR            = "FF_"+s_corr+"_TT_J_"+s_MCsum+"_noGen_"+s_drb+"_"+s_CR+".root";

const TString FF_corr_DY_J_MCsum_noGen_mtll_CR    = "FF_"+s_corr+"_DY_J_"+s_MCsum+"_noGen_"+s_mtll+"_"    +s_CR+".root";
const TString FF_corr_DY_J_MCsum_noGen_mtll_fit_CR= "FF_"+s_corr+"_DY_J_"+s_MCsum+"_noGen_"+s_mtll+"_fit_"+s_CR+".root";
const TString FF_corr_DY_J_MCsum_noGen_mtll_1p_fit_CR= "FF_"+s_corr+"_DY_J_"+s_MCsum+"_noGen_"+s_mtll+"_1p_fit_"+s_CR+".root";
const TString FF_corr_DY_J_MCsum_noGen_mtll_3p_fit_CR= "FF_"+s_corr+"_DY_J_"+s_MCsum+"_noGen_"+s_mtll+"_3p_fit_"+s_CR+".root";
const TString FF_DY_J_only_mtll_fit_CR             = "FF_DY_J_only_"+s_mtll+"_fit_"+s_CR+".root";
const TString FF_DY_J_only_mtll_1p_fit_CR          = "FF_DY_J_only_"+s_mtll+"_1p_fit_"+s_CR+".root";
const TString FF_DY_J_only_mtll_3p_fit_CR          = "FF_DY_J_only_"+s_mtll+"_3p_fit_"+s_CR+".root";

// Fakefactor files (CR corrected)
const TString FF_corr_Wjets_data                    = "FF_"+s_corr+"_Wjets_data.root";
const TString FF_corr_Wjets_data_weighted           = "FF_"+s_corr+"_Wjets_data_"+s_weighted+".root";
const TString FF_corr_Wjets_MCsum_noGen             = "FF_"+s_corr+"_Wjets_"+s_MCsum+"_noGen.root";
const TString FF_corr_Wjets_MC_noGen                = "FF_"+s_corr+"_Wjets_MC_noGen.root";
const TString FF_corr_Wjets_MCsum_noGen_nonclosure  = "FF_"+s_corr+"_Wjets_"+s_MCsum+"_noGen_nonclosure.root";
const TString FF_corr_Wjets_MCsum_noGen_nonclosure_SS_SR  = "FF_"+s_corr+"_Wjets_"+s_MCsum+"_noGen_nonclosure_SS_SR.root";
const TString FF_corr_Wjets_MC_noGen_nonclosure  = "FF_"+s_corr+"_Wjets_MC_noGen_nonclosure.root";
const TString FF_corr_Wjets_MC_noGen_mtcorr      = "FF_"+s_corr+"_Wjets_MC_noGen_mtcorr.root";
const TString FF_corr_Wjets_MC_noGen_mtcorr_SS_SR      = "FF_"+s_corr+"_Wjets_MC_noGen_mtcorr_SS_SR.root";
const TString FF_corr_Wjets_MCsum_noGen_weighted    = "FF_"+s_corr+"_Wjets_"+s_MCsum+"_noGen_"+s_weighted+".root";
const TString FF_corr_Wjets_MCsum_noGen_SR          = "FF_"+s_corr+"_Wjets_"+s_MCsum+"_noGen_"+s_SR+".root";
const TString FF_corr_Wjets_MCsum_noGen_SR_weighted = "FF_"+s_corr+"_Wjets_"+s_MCsum+"_noGen_"+s_SR+"_"+s_weighted+".root";
const TString FF_corr_Wjets_MCsum_Gen               = "FF_"+s_corr+"_Wjets_"+s_MCsum+"_Gen.root";
const TString FF_corr_Wjets_MCsum_Gen_weighted      = "FF_"+s_corr+"_Wjets_"+s_MCsum+"_Gen_"+s_weighted+".root";

const TString FF_corr_DY_data                    = "FF_"+s_corr+"_DY_data.root";
const TString FF_corr_DY_data_weighted           = "FF_"+s_corr+"_DY_data_"+s_weighted+".root";
const TString FF_corr_DY_MCsum_noGen             = "FF_"+s_corr+"_DY_"+s_MCsum+"_noGen.root";
const TString FF_corr_DY_MCsum_noGen_weighted    = "FF_"+s_corr+"_DY_"+s_MCsum+"_noGen_"+s_weighted+".root";
const TString FF_corr_DY_MCsum_noGen_SR          = "FF_"+s_corr+"_DY_"+s_MCsum+"_noGen_"+s_SR+".root";
const TString FF_corr_DY_MCsum_noGen_SR_weighted = "FF_"+s_corr+"_DY_"+s_MCsum+"_noGen_"+s_SR+"_"+s_weighted+".root";
const TString FF_corr_DY_MCsum_Gen               = "FF_"+s_corr+"_DY_"+s_MCsum+"_Gen.root";
const TString FF_corr_DY_MCsum_Gen_weighted      = "FF_"+s_corr+"_DY_"+s_MCsum+"_Gen_"+s_weighted+".root";

const TString FF_corr_TT_data                    = "FF_"+s_corr+"_TT_data.root";
const TString FF_corr_TT_data_weighted           = "FF_"+s_corr+"_TT_data_"+s_weighted+".root";
const TString FF_corr_TT_MCsum_noGen             = "FF_"+s_corr+"_TT_"+s_MCsum+"_noGen.root";
const TString FF_corr_TT_MCsum_noGen_weighted    = "FF_"+s_corr+"_TT_"+s_MCsum+"_noGen_"+s_weighted+".root";
const TString FF_corr_TT_MCsum_noGen_SR          = "FF_"+s_corr+"_TT_"+s_MCsum+"_noGen_"+s_SR+".root";
const TString FF_corr_TT_MCsum_noGen_SR_weighted = "FF_"+s_corr+"_TT_"+s_MCsum+"_noGen_"+s_SR+"_"+s_weighted+".root";
const TString FF_corr_TT_MCsum_Gen               = "FF_"+s_corr+"_TT_"+s_MCsum+"_Gen.root";
const TString FF_corr_TT_MCsum_Gen_weighted      = "FF_"+s_corr+"_TT_"+s_MCsum+"_Gen_"+s_weighted+".root";

const TString FF_corr_QCD_data                   = "FF_"+s_corr+"_QCD_data.root";
const TString FF_corr_QCD_data_weighted          = "FF_"+s_corr+"_QCD_data_"+s_weighted+".root";
const TString FF_corr_QCD_MCsum_noGen            = "FF_"+s_corr+"_QCD_"+s_MCsum+"_noGen.root";
const TString FF_corr_QCD_MCsum_noGen_muisocorr  = "FF_"+s_corr+"_QCD_"+s_MCsum+"_noGen_muisocorr.root";
const TString FF_corr_QCD_MCsum_noGen_muisocorr_AI  = "FF_"+s_corr+"_QCD_"+s_MCsum+"_noGen_muisocorr_AI.root";
const TString FF_corr_QCD_MCsum_noGen_nonclosure = "FF_"+s_corr+"_QCD_"+s_MCsum+"_noGen_nonclosure.root";
const TString FF_corr_QCD_MCsum_noGen_nonclosure_AI = "FF_"+s_corr+"_QCD_"+s_MCsum+"_noGen_nonclosure_AI.root";
const TString FF_corr_QCD_MCsum_noGen_OSSScorr  = "FF_"+s_corr+"_QCD_"+s_MCsum+"_noGen_OSSScorr.root";
const TString FF_corr_QCD_MCsum_noGen_OS           = "FF_"+s_corr+"_QCD_"+s_MCsum+"_noGen_OS.root";  
const TString FF_corr_QCD_MCsum_noGen_weighted   = "FF_"+s_corr+"_QCD_"+s_MCsum+"_noGen_"+s_weighted+".root";
const TString FF_corr_QCD_MCsum_noGen_SR         = "FF_"+s_corr+"_QCD_"+s_MCsum+"_noGen_"+s_SR+".root";
const TString FF_corr_QCD_MCsum_noGen_AI         = "FF_"+s_corr+"_QCD_"+s_MCsum+"_noGen_AI.root";
const TString FF_corr_QCD_MCsum_noGen_SR_weighted= "FF_"+s_corr+"_QCD_"+s_MCsum+"_noGen_"+s_SR+"_"+s_weighted+".root";
const TString FF_corr_QCD_MCsum_Gen              = "FF_"+s_corr+"_QCD_"+s_MCsum+"_Gen.root";
const TString FF_corr_QCD_MCsum_Gen_weighted     = "FF_"+s_corr+"_QCD_"+s_MCsum+"_Gen_"+s_weighted+".root";

const TString FF_corr_QCDISO_MCsum_noGen            = "FF_"+s_corr+"_QCDISO_"+s_MCsum+"_noGen.root";

// Those are just copies of the above files.
const TString FF_corr_data_sum                   = "FF_"+s_corr+"_data_sum.root";
const TString FF_corr_MCsum_noGen_sum            = "FF_"+s_corr+"_"+s_MCsum+"_noGen_sum.root";
const TString FF_corr_MCsum_Gen_sum              = "FF_"+s_corr+"_"+s_MCsum+"_Gen_sum.root";
const TString FF_corr_MC_noGen_sum               = "FF_"+s_corr+"_"+s_MC+"_noGen_sum.root";
const TString FF_corr_MC_Gen_sum                 = "FF_"+s_corr+"_"+s_MC+"_Gen_sum.root";


// Background estimation files
// TODO check if '_weighted' is necessary for MCsum files, remove it if redundant!
const TString bg_est_Wjets_mt_data                   = "bg_est_Wjets_"+s_mt+"_data.root";
const TString bg_est_Wjets_mt_MC_Gen                 = "bg_est_Wjets_"+s_mt+"_"+s_MC+"_Gen.root";
const TString bg_est_Wjets_mt_MC_noGen               = "bg_est_Wjets_"+s_mt+"_"+s_MC+"_noGen.root";
const TString bg_est_Wjets_mt_MCsum_Gen              = "bg_est_Wjets_"+s_mt+"_"+s_MCsum+"_Gen.root";
const TString bg_est_Wjets_mt_MCsum_noGen            = "bg_est_Wjets_"+s_mt+"_"+s_MCsum+"_noGen.root";
const TString bg_est_Wjets_mvis_data                 = "bg_est_Wjets_"+s_mvis+"_data.root";
const TString bg_est_Wjets_mvis_MC_Gen               = "bg_est_Wjets_"+s_mvis+"_"+s_MC+"_Gen.root";
const TString bg_est_Wjets_mvis_MC_noGen             = "bg_est_Wjets_"+s_mvis+"_"+s_MC+"_noGen.root";
const TString bg_est_Wjets_mvis_MCsum_Gen            = "bg_est_Wjets_"+s_mvis+"_"+s_MCsum+"_Gen.root";
const TString bg_est_Wjets_mvis_MCsum_noGen          = "bg_est_Wjets_"+s_mvis+"_"+s_MCsum+"_noGen.root";
const TString bg_est_Wjets_pt_data                   = "bg_est_Wjets_"+s_pt+"_data.root";
const TString bg_est_Wjets_pt_MC_Gen                 = "bg_est_Wjets_"+s_pt+"_"+s_MC+"_Gen.root";
const TString bg_est_Wjets_pt_MC_noGen               = "bg_est_Wjets_"+s_pt+"_"+s_MC+"_noGen.root";
const TString bg_est_Wjets_pt_MCsum_Gen              = "bg_est_Wjets_"+s_pt+"_"+s_MCsum+"_Gen.root";
const TString bg_est_Wjets_pt_MCsum_noGen            = "bg_est_Wjets_"+s_pt+"_"+s_MCsum+"_noGen.root";

const TString bg_est_corr_Wjets_mt_data                   = "bg_est_"+s_corr+"_Wjets_"+s_mt+"_data.root";
const TString bg_est_corr_Wjets_mt_MC_Gen                 = "bg_est_"+s_corr+"_Wjets_"+s_mt+"_"+s_MC+"_Gen.root";
const TString bg_est_corr_Wjets_mt_MC_noGen               = "bg_est_"+s_corr+"_Wjets_"+s_mt+"_"+s_MC+"_noGen.root";
const TString bg_est_corr_Wjets_mt_MCsum_Gen              = "bg_est_"+s_corr+"_Wjets_"+s_mt+"_"+s_MCsum+"_Gen.root";
const TString bg_est_corr_Wjets_mt_MCsum_noGen            = "bg_est_"+s_corr+"_Wjets_"+s_mt+"_"+s_MCsum+"_noGen.root";
const TString bg_est_corr_Wjets_mvis_data                 = "bg_est_"+s_corr+"_Wjets_"+s_mvis+"_data.root";
const TString bg_est_corr_Wjets_mvis_MC_Gen               = "bg_est_"+s_corr+"_Wjets_"+s_mvis+"_"+s_MC+"_Gen.root";
const TString bg_est_corr_Wjets_mvis_MC_noGen             = "bg_est_"+s_corr+"_Wjets_"+s_mvis+"_"+s_MC+"_noGen.root";
const TString bg_est_corr_Wjets_mvis_MCsum_Gen            = "bg_est_"+s_corr+"_Wjets_"+s_mvis+"_"+s_MCsum+"_Gen.root";
const TString bg_est_corr_Wjets_mvis_MCsum_noGen          = "bg_est_"+s_corr+"_Wjets_"+s_mvis+"_"+s_MCsum+"_noGen.root";
const TString bg_est_corr_Wjets_pt_data                   = "bg_est_"+s_corr+"_Wjets_"+s_pt+"_data.root";
const TString bg_est_corr_Wjets_pt_MC_Gen                 = "bg_est_"+s_corr+"_Wjets_"+s_pt+"_"+s_MC+"_Gen.root";
const TString bg_est_corr_Wjets_pt_MC_noGen               = "bg_est_"+s_corr+"_Wjets_"+s_pt+"_"+s_MC+"_noGen.root";
const TString bg_est_corr_Wjets_pt_MCsum_Gen              = "bg_est_"+s_corr+"_Wjets_"+s_pt+"_"+s_MCsum+"_Gen.root";
const TString bg_est_corr_Wjets_pt_MCsum_noGen            = "bg_est_"+s_corr+"_Wjets_"+s_pt+"_"+s_MCsum+"_noGen.root";

const TString bg_est_DY_J_mt_data                   = "bg_est_DY_J_"+s_mt+"_data.root";
const TString bg_est_DY_J_mt_MC_Gen                 = "bg_est_DY_J_"+s_mt+"_"+s_MC+"_Gen.root";
const TString bg_est_DY_J_mt_MC_noGen               = "bg_est_DY_J_"+s_mt+"_"+s_MC+"_noGen.root";
const TString bg_est_DY_J_mt_MCsum_Gen              = "bg_est_DY_J_"+s_mt+"_"+s_MCsum+"_Gen.root";
const TString bg_est_DY_J_mt_MCsum_noGen            = "bg_est_DY_J_"+s_mt+"_"+s_MCsum+"_noGen.root";
const TString bg_est_DY_J_mvis_data                 = "bg_est_DY_J_"+s_mvis+"_data.root";
const TString bg_est_DY_J_mvis_MC_Gen               = "bg_est_DY_J_"+s_mvis+"_"+s_MC+"_Gen.root";
const TString bg_est_DY_J_mvis_MC_noGen             = "bg_est_DY_J_"+s_mvis+"_"+s_MC+"_noGen.root";
const TString bg_est_DY_J_mvis_MCsum_Gen            = "bg_est_DY_J_"+s_mvis+"_"+s_MCsum+"_Gen.root";
const TString bg_est_DY_J_mvis_MCsum_noGen          = "bg_est_DY_J_"+s_mvis+"_"+s_MCsum+"_noGen.root";
const TString bg_est_DY_J_pt_data                   = "bg_est_DY_J_"+s_pt+"_data.root";
const TString bg_est_DY_J_pt_MC_Gen                 = "bg_est_DY_J_"+s_pt+"_"+s_MC+"_Gen.root";
const TString bg_est_DY_J_pt_MC_noGen               = "bg_est_DY_J_"+s_pt+"_"+s_MC+"_noGen.root";
const TString bg_est_DY_J_pt_MCsum_Gen              = "bg_est_DY_J_"+s_pt+"_"+s_MCsum+"_Gen.root";
const TString bg_est_DY_J_pt_MCsum_noGen            = "bg_est_DY_J_"+s_pt+"_"+s_MCsum+"_noGen.root";

const TString bg_est_corr_DY_J_mt_data                   = "bg_est_"+s_corr+"_DY_J_"+s_mt+"_data.root";
const TString bg_est_corr_DY_J_mt_MC_Gen                 = "bg_est_"+s_corr+"_DY_J_"+s_mt+"_"+s_MC+"_Gen.root";
const TString bg_est_corr_DY_J_mt_MC_noGen               = "bg_est_"+s_corr+"_DY_J_"+s_mt+"_"+s_MC+"_noGen.root";
const TString bg_est_corr_DY_J_mt_MCsum_Gen              = "bg_est_"+s_corr+"_DY_J_"+s_mt+"_"+s_MCsum+"_Gen.root";
const TString bg_est_corr_DY_J_mt_MCsum_noGen            = "bg_est_"+s_corr+"_DY_J_"+s_mt+"_"+s_MCsum+"_noGen.root";
const TString bg_est_corr_DY_J_mvis_data                 = "bg_est_"+s_corr+"_DY_J_"+s_mvis+"_data.root";
const TString bg_est_corr_DY_J_mvis_MC_Gen               = "bg_est_"+s_corr+"_DY_J_"+s_mvis+"_"+s_MC+"_Gen.root";
const TString bg_est_corr_DY_J_mvis_MC_noGen             = "bg_est_"+s_corr+"_DY_J_"+s_mvis+"_"+s_MC+"_noGen.root";
const TString bg_est_corr_DY_J_mvis_MCsum_Gen            = "bg_est_"+s_corr+"_DY_J_"+s_mvis+"_"+s_MCsum+"_Gen.root";
const TString bg_est_corr_DY_J_mvis_MCsum_noGen          = "bg_est_"+s_corr+"_DY_J_"+s_mvis+"_"+s_MCsum+"_noGen.root";
const TString bg_est_corr_DY_J_pt_data                   = "bg_est_"+s_corr+"_DY_J_"+s_pt+"_data.root";
const TString bg_est_corr_DY_J_pt_MC_Gen                 = "bg_est_"+s_corr+"_DY_J_"+s_pt+"_"+s_MC+"_Gen.root";
const TString bg_est_corr_DY_J_pt_MC_noGen               = "bg_est_"+s_corr+"_DY_J_"+s_pt+"_"+s_MC+"_noGen.root";
const TString bg_est_corr_DY_J_pt_MCsum_Gen              = "bg_est_"+s_corr+"_DY_J_"+s_pt+"_"+s_MCsum+"_Gen.root";
const TString bg_est_corr_DY_J_pt_MCsum_noGen            = "bg_est_"+s_corr+"_DY_J_"+s_pt+"_"+s_MCsum+"_noGen.root";

const TString bg_est_TT_J_mt_data                   = "bg_est_TT_J_"+s_mt+"_data.root";
const TString bg_est_TT_J_mt_MC_Gen                 = "bg_est_TT_J_"+s_mt+"_"+s_MC+"_Gen.root";
const TString bg_est_TT_J_mt_MC_noGen               = "bg_est_TT_J_"+s_mt+"_"+s_MC+"_noGen.root";
const TString bg_est_TT_J_mt_MCsum_Gen              = "bg_est_TT_J_"+s_mt+"_"+s_MCsum+"_Gen.root";
const TString bg_est_TT_J_mt_MCsum_noGen            = "bg_est_TT_J_"+s_mt+"_"+s_MCsum+"_noGen.root";
const TString bg_est_TT_J_mvis_data                 = "bg_est_TT_J_"+s_mvis+"_data.root";
const TString bg_est_TT_J_mvis_MC_Gen               = "bg_est_TT_J_"+s_mvis+"_"+s_MC+"_Gen.root";
const TString bg_est_TT_J_mvis_MC_noGen             = "bg_est_TT_J_"+s_mvis+"_"+s_MC+"_noGen.root";
const TString bg_est_TT_J_mvis_MCsum_Gen            = "bg_est_TT_J_"+s_mvis+"_"+s_MCsum+"_Gen.root";
const TString bg_est_TT_J_mvis_MCsum_noGen          = "bg_est_TT_J_"+s_mvis+"_"+s_MCsum+"_noGen.root";
const TString bg_est_TT_J_pt_data                   = "bg_est_TT_J_"+s_pt+"_data.root";
const TString bg_est_TT_J_pt_MC_Gen                 = "bg_est_TT_J_"+s_pt+"_"+s_MC+"_Gen.root";
const TString bg_est_TT_J_pt_MC_noGen               = "bg_est_TT_J_"+s_pt+"_"+s_MC+"_noGen.root";
const TString bg_est_TT_J_pt_MCsum_Gen              = "bg_est_TT_J_"+s_pt+"_"+s_MCsum+"_Gen.root";
const TString bg_est_TT_J_pt_MCsum_noGen            = "bg_est_TT_J_"+s_pt+"_"+s_MCsum+"_noGen.root";

const TString bg_est_corr_TT_J_mt_data                   = "bg_est_"+s_corr+"_TT_J_"+s_mt+"_data.root";
const TString bg_est_corr_TT_J_mt_MC_Gen                 = "bg_est_"+s_corr+"_TT_J_"+s_mt+"_"+s_MC+"_Gen.root";
const TString bg_est_corr_TT_J_mt_MC_noGen               = "bg_est_"+s_corr+"_TT_J_"+s_mt+"_"+s_MC+"_noGen.root";
const TString bg_est_corr_TT_J_mt_MCsum_Gen              = "bg_est_"+s_corr+"_TT_J_"+s_mt+"_"+s_MCsum+"_Gen.root";
const TString bg_est_corr_TT_J_mt_MCsum_noGen            = "bg_est_"+s_corr+"_TT_J_"+s_mt+"_"+s_MCsum+"_noGen.root";
const TString bg_est_corr_TT_J_mvis_data                 = "bg_est_"+s_corr+"_TT_J_"+s_mvis+"_data.root";
const TString bg_est_corr_TT_J_mvis_MC_Gen               = "bg_est_"+s_corr+"_TT_J_"+s_mvis+"_"+s_MC+"_Gen.root";
const TString bg_est_corr_TT_J_mvis_MC_noGen             = "bg_est_"+s_corr+"_TT_J_"+s_mvis+"_"+s_MC+"_noGen.root";
const TString bg_est_corr_TT_J_mvis_MCsum_Gen            = "bg_est_"+s_corr+"_TT_J_"+s_mvis+"_"+s_MCsum+"_Gen.root";
const TString bg_est_corr_TT_J_mvis_MCsum_noGen          = "bg_est_"+s_corr+"_TT_J_"+s_mvis+"_"+s_MCsum+"_noGen.root";
const TString bg_est_corr_TT_J_pt_data                   = "bg_est_"+s_corr+"_TT_J_"+s_pt+"_data.root";
const TString bg_est_corr_TT_J_pt_MC_Gen                 = "bg_est_"+s_corr+"_TT_J_"+s_pt+"_"+s_MC+"_Gen.root";
const TString bg_est_corr_TT_J_pt_MC_noGen               = "bg_est_"+s_corr+"_TT_J_"+s_pt+"_"+s_MC+"_noGen.root";
const TString bg_est_corr_TT_J_pt_MCsum_Gen              = "bg_est_"+s_corr+"_TT_J_"+s_pt+"_"+s_MCsum+"_Gen.root";
const TString bg_est_corr_TT_J_pt_MCsum_noGen            = "bg_est_"+s_corr+"_TT_J_"+s_pt+"_"+s_MCsum+"_noGen.root";

const TString bg_est_QCD_mt_data                   = "bg_est_QCD_"+s_mt+"_data.root";
const TString bg_est_QCD_mt_MC_Gen                 = "bg_est_QCD_"+s_mt+"_"+s_MC+"_Gen.root";
const TString bg_est_QCD_mt_MC_noGen               = "bg_est_QCD_"+s_mt+"_"+s_MC+"_noGen.root";
const TString bg_est_QCD_mt_MCsum_Gen              = "bg_est_QCD_"+s_mt+"_"+s_MCsum+"_Gen.root";
const TString bg_est_QCD_mt_MCsum_noGen            = "bg_est_QCD_"+s_mt+"_"+s_MCsum+"_noGen.root";
const TString bg_est_QCD_mvis_data                 = "bg_est_QCD_"+s_mvis+"_data.root";
const TString bg_est_QCD_mvis_MC_Gen               = "bg_est_QCD_"+s_mvis+"_"+s_MC+"_Gen.root";
const TString bg_est_QCD_mvis_MC_noGen             = "bg_est_QCD_"+s_mvis+"_"+s_MC+"_noGen.root";
const TString bg_est_QCD_mvis_MCsum_Gen            = "bg_est_QCD_"+s_mvis+"_"+s_MCsum+"_Gen.root";
const TString bg_est_QCD_mvis_MCsum_noGen          = "bg_est_QCD_"+s_mvis+"_"+s_MCsum+"_noGen.root";
const TString bg_est_QCD_pt_data                   = "bg_est_QCD_"+s_pt+"_data.root";
const TString bg_est_QCD_pt_MC_Gen                 = "bg_est_QCD_"+s_pt+"_"+s_MC+"_Gen.root";
const TString bg_est_QCD_pt_MC_noGen               = "bg_est_QCD_"+s_pt+"_"+s_MC+"_noGen.root";
const TString bg_est_QCD_pt_MCsum_Gen              = "bg_est_QCD_"+s_pt+"_"+s_MCsum+"_Gen.root";
const TString bg_est_QCD_pt_MCsum_noGen            = "bg_est_QCD_"+s_pt+"_"+s_MCsum+"_noGen.root";

const TString bg_est_corr_QCD_mt_data                   = "bg_est_"+s_corr+"_QCD_"+s_mt+"_data.root";
const TString bg_est_corr_QCD_mt_MC_Gen                 = "bg_est_"+s_corr+"_QCD_"+s_mt+"_"+s_MC+"_Gen.root";
const TString bg_est_corr_QCD_mt_MC_noGen               = "bg_est_"+s_corr+"_QCD_"+s_mt+"_"+s_MC+"_noGen.root";
const TString bg_est_corr_QCD_mt_MCsum_Gen              = "bg_est_"+s_corr+"_QCD_"+s_mt+"_"+s_MCsum+"_Gen.root";
const TString bg_est_corr_QCD_mt_MCsum_noGen            = "bg_est_"+s_corr+"_QCD_"+s_mt+"_"+s_MCsum+"_noGen.root";
const TString bg_est_corr_QCD_mvis_data                 = "bg_est_"+s_corr+"_QCD_"+s_mvis+"_data.root";
const TString bg_est_corr_QCD_mvis_MC_Gen               = "bg_est_"+s_corr+"_QCD_"+s_mvis+"_"+s_MC+"_Gen.root";
const TString bg_est_corr_QCD_mvis_MC_noGen             = "bg_est_"+s_corr+"_QCD_"+s_mvis+"_"+s_MC+"_noGen.root";
const TString bg_est_corr_QCD_mvis_MCsum_Gen            = "bg_est_"+s_corr+"_QCD_"+s_mvis+"_"+s_MCsum+"_Gen.root";
const TString bg_est_corr_QCD_mvis_MCsum_noGen          = "bg_est_"+s_corr+"_QCD_"+s_mvis+"_"+s_MCsum+"_noGen.root";
const TString bg_est_corr_QCD_pt_data                   = "bg_est_"+s_corr+"_QCD_"+s_pt+"_data.root";
const TString bg_est_corr_QCD_pt_MC_Gen                 = "bg_est_"+s_corr+"_QCD_"+s_pt+"_"+s_MC+"_Gen.root";
const TString bg_est_corr_QCD_pt_MC_noGen               = "bg_est_"+s_corr+"_QCD_"+s_pt+"_"+s_MC+"_noGen.root";
const TString bg_est_corr_QCD_pt_MCsum_Gen              = "bg_est_"+s_corr+"_QCD_"+s_pt+"_"+s_MCsum+"_Gen.root";
const TString bg_est_corr_QCD_pt_MCsum_noGen            = "bg_est_"+s_corr+"_QCD_"+s_pt+"_"+s_MCsum+"_noGen.root";

const TString bg_est_corr_QCDISO_mvis_MCsum_noGen       = "bg_est_"+s_corr+"_QCDISO_"+s_mvis+"_"+s_MCsum+"_noGen.root";
const TString bg_est_corr_QCDISO_mt_MCsum_noGen         = "bg_est_"+s_corr+"_QCDISO_"+s_mt+"_"+s_MCsum+"_noGen.root";
const TString bg_est_corr_QCDISO_pt_MCsum_noGen         = "bg_est_"+s_corr+"_QCDISO_"+s_pt+"_"+s_MCsum+"_noGen.root";


// Background estimation files CR norm
const TString bg_est_Wjets_mt_CRnorm    = "bg_est_CRNorm_Wjets_"+s_mt+".root";
const TString bg_est_Wjets_mvis_CRnorm  = "bg_est_CRNorm_Wjets_"+s_mvis+".root";
const TString bg_est_Wjets_pt_CRnorm    = "bg_est_CRNorm_Wjets_"+s_pt+".root";

const TString bg_est_DY_mt_CRnorm   = "bg_est_CRNorm_DY_"+s_mt+".root";
const TString bg_est_DY_mvis_CRnorm = "bg_est_CRNorm_DY_"+s_mvis+".root";
const TString bg_est_DY_pt_CRnorm   = "bg_est_CRNorm_DY_"+s_pt+".root";

// In SR
const TString SR_Wjets_mt_sim     = path_sim + s_SR+"_Wjets_"+s_mt+".root";
const TString SR_Wjets_mvis_sim   = path_sim + s_SR+"_Wjets_"+s_mvis+".root";
const TString SR_Wjets_pt_sim     = path_sim + s_SR+"_Wjets_"+s_pt+".root";

const TString SR_DY_mt_sim    = path_sim + s_SR+"_DY_"+s_mt+".root";
const TString SR_DY_mvis_sim  = path_sim + s_SR+"_DY_"+s_mvis+".root";
const TString SR_DY_pt_sim    = path_sim + s_SR+"_DY_"+s_pt+".root";

const TString SR_DY_TT_mt_sim   = path_sim + s_SR+"_DY_TT_"+s_mt+".root";
const TString SR_DY_TT_mvis_sim = path_sim + s_SR+"_DY_TT_"+s_mvis+".root";
const TString SR_DY_TT_pt_sim   = path_sim + s_SR+"_DY_TT_"+s_pt+".root";

const TString SR_DY_L_mt_sim    = path_sim + s_SR+"_DY_L_"+s_mt+".root";
const TString SR_DY_L_mvis_sim  = path_sim + s_SR+"_DY_L_"+s_mvis+".root";
const TString SR_DY_L_pt_sim    = path_sim + s_SR+"_DY_L_"+s_pt+".root";

const TString SR_DY_J_mt_sim     = path_sim + s_SR+"_DY_J_"+s_mt+".root";
const TString SR_DY_J_mvis_sim   = path_sim + s_SR+"_DY_J_"+s_mvis+".root";
const TString SR_DY_J_pt_sim     = path_sim + s_SR+"_DY_J_"+s_pt+".root";

const TString SR_TT_mt_sim     = path_sim + s_SR+"_TT_"+s_mt+".root";
const TString SR_TT_mvis_sim   = path_sim + s_SR+"_TT_"+s_mvis+".root";
const TString SR_TT_pt_sim     = path_sim + s_SR+"_TT_"+s_pt+".root";

const TString SR_TT_T_mt_sim     = path_sim + s_SR+"_TT_T_"+s_mt+".root";
const TString SR_TT_T_mvis_sim   = path_sim + s_SR+"_TT_T_"+s_mvis+".root";
const TString SR_TT_T_pt_sim     = path_sim + s_SR+"_TT_T_"+s_pt+".root";

const TString SR_TT_J_mt_sim     = path_sim + s_SR+"_TT_J_"+s_mt+".root";
const TString SR_TT_J_mvis_sim   = path_sim + s_SR+"_TT_J_"+s_mvis+".root";
const TString SR_TT_J_pt_sim     = path_sim + s_SR+"_TT_J_"+s_pt+".root";

const TString SR_TT_L_mt_sim     = path_sim + s_SR+"_TT_L_"+s_mt+".root";
const TString SR_TT_L_mvis_sim   = path_sim + s_SR+"_TT_L_"+s_mvis+".root";
const TString SR_TT_L_pt_sim     = path_sim + s_SR+"_TT_L_"+s_pt+".root";

const TString SR_QCD_mt_sim     = path_sim + s_SR+"_QCD_"+s_mt+".root";
const TString SR_QCD_mvis_sim   = path_sim + s_SR+"_QCD_"+s_mvis+".root";
const TString SR_QCD_pt_sim     = path_sim + s_SR+"_QCD_"+s_pt+".root";

const TString SR_VV_mt_sim      =path_sim + s_SR+"_VV_"+s_mt+".root";
const TString SR_VV_mvis_sim    =path_sim + s_SR+"_VV_"+s_mvis+".root";
const TString SR_VV_pt_sim      =path_sim + s_SR+"_VV_"+s_pt+".root";

const TString SR_VV_T_mt_sim      =path_sim + s_SR+"_VV_T_"+s_mt+".root";
const TString SR_VV_T_mvis_sim    =path_sim + s_SR+"_VV_T_"+s_mvis+".root";
const TString SR_VV_T_pt_sim      =path_sim + s_SR+"_VV_T_"+s_pt+".root";

const TString SR_VV_J_mt_sim      =path_sim + s_SR+"_VV_J_"+s_mt+".root";
const TString SR_VV_J_mvis_sim    =path_sim + s_SR+"_VV_J_"+s_mvis+".root";
const TString SR_VV_J_pt_sim      =path_sim + s_SR+"_VV_J_"+s_pt+".root";

const TString SR_VV_L_mt_sim      =path_sim + s_SR+"_VV_L_"+s_mt+".root";
const TString SR_VV_L_mvis_sim    =path_sim + s_SR+"_VV_L_"+s_mvis+".root";
const TString SR_VV_L_pt_sim      =path_sim + s_SR+"_VV_L_"+s_pt+".root";

// In SS_SR
const TString SS_SR_Wjets_mt_sim     = path_sim + s_SS_SR+"_Wjets_"+s_mt+".root";
const TString SS_SR_Wjets_mvis_sim   = path_sim + s_SS_SR+"_Wjets_"+s_mvis+".root";
const TString SS_SR_Wjets_pt_sim     = path_sim + s_SS_SR+"_Wjets_"+s_pt+".root";

const TString SS_SR_DY_mt_sim    = path_sim + s_SS_SR+"_DY_"+s_mt+".root";
const TString SS_SR_DY_mvis_sim  = path_sim + s_SS_SR+"_DY_"+s_mvis+".root";
const TString SS_SR_DY_pt_sim    = path_sim + s_SS_SR+"_DY_"+s_pt+".root";

const TString SS_SR_DY_TT_mt_sim   = path_sim + s_SS_SR+"_DY_TT_"+s_mt+".root";
const TString SS_SR_DY_TT_mvis_sim = path_sim + s_SS_SR+"_DY_TT_"+s_mvis+".root";
const TString SS_SR_DY_TT_pt_sim   = path_sim + s_SS_SR+"_DY_TT_"+s_pt+".root";

const TString SS_SR_DY_L_mt_sim    = path_sim + s_SS_SR+"_DY_L_"+s_mt+".root";
const TString SS_SR_DY_L_mvis_sim  = path_sim + s_SS_SR+"_DY_L_"+s_mvis+".root";
const TString SS_SR_DY_L_pt_sim    = path_sim + s_SS_SR+"_DY_L_"+s_pt+".root";

const TString SS_SR_DY_J_mt_sim     = path_sim + s_SS_SR+"_DY_J_"+s_mt+".root";
const TString SS_SR_DY_J_mvis_sim   = path_sim + s_SS_SR+"_DY_J_"+s_mvis+".root";
const TString SS_SR_DY_J_pt_sim     = path_sim + s_SS_SR+"_DY_J_"+s_pt+".root";

const TString SS_SR_TT_mt_sim     = path_sim + s_SS_SR+"_TT_"+s_mt+".root";
const TString SS_SR_TT_mvis_sim   = path_sim + s_SS_SR+"_TT_"+s_mvis+".root";
const TString SS_SR_TT_pt_sim     = path_sim + s_SS_SR+"_TT_"+s_pt+".root";

const TString SS_SR_TT_T_mt_sim     = path_sim + s_SS_SR+"_TT_T_"+s_mt+".root";
const TString SS_SR_TT_T_mvis_sim   = path_sim + s_SS_SR+"_TT_T_"+s_mvis+".root";
const TString SS_SR_TT_T_pt_sim     = path_sim + s_SS_SR+"_TT_T_"+s_pt+".root";

const TString SS_SR_TT_J_mt_sim     = path_sim + s_SS_SR+"_TT_J_"+s_mt+".root";
const TString SS_SR_TT_J_mvis_sim   = path_sim + s_SS_SR+"_TT_J_"+s_mvis+".root";
const TString SS_SR_TT_J_pt_sim     = path_sim + s_SS_SR+"_TT_J_"+s_pt+".root";

const TString SS_SR_TT_L_mt_sim     = path_sim + s_SS_SR+"_TT_L_"+s_mt+".root";
const TString SS_SR_TT_L_mvis_sim   = path_sim + s_SS_SR+"_TT_L_"+s_mvis+".root";
const TString SS_SR_TT_L_pt_sim     = path_sim + s_SS_SR+"_TT_L_"+s_pt+".root";

const TString SS_SR_QCD_mt_sim     = path_sim + s_SS_SR+"_QCD_"+s_mt+".root";
const TString SS_SR_QCD_mvis_sim   = path_sim + s_SS_SR+"_QCD_"+s_mvis+".root";
const TString SS_SR_QCD_pt_sim     = path_sim + s_SS_SR+"_QCD_"+s_pt+".root";

const TString SS_SR_VV_mt_sim      =path_sim + s_SS_SR+"_VV_"+s_mt+".root";
const TString SS_SR_VV_mvis_sim    =path_sim + s_SS_SR+"_VV_"+s_mvis+".root";
const TString SS_SR_VV_pt_sim      =path_sim + s_SS_SR+"_VV_"+s_pt+".root";

const TString SS_SR_VV_T_mt_sim      =path_sim + s_SS_SR+"_VV_T_"+s_mt+".root";
const TString SS_SR_VV_T_mvis_sim    =path_sim + s_SS_SR+"_VV_T_"+s_mvis+".root";
const TString SS_SR_VV_T_pt_sim      =path_sim + s_SS_SR+"_VV_T_"+s_pt+".root";

const TString SS_SR_VV_J_mt_sim      =path_sim + s_SS_SR+"_VV_J_"+s_mt+".root";
const TString SS_SR_VV_J_mvis_sim    =path_sim + s_SS_SR+"_VV_J_"+s_mvis+".root";
const TString SS_SR_VV_J_pt_sim      =path_sim + s_SS_SR+"_VV_J_"+s_pt+".root";

const TString SS_SR_VV_L_mt_sim      =path_sim + s_SS_SR+"_VV_L_"+s_mt+".root";
const TString SS_SR_VV_L_mvis_sim    =path_sim + s_SS_SR+"_VV_L_"+s_mvis+".root";
const TString SS_SR_VV_L_pt_sim      =path_sim + s_SS_SR+"_VV_L_"+s_pt+".root";

// Control region histograms
const TString CR_Wjets_mt_Wjets    = path_sim + s_CR+"_Wjets_"+s_mt+"_Wjets.root";
const TString CR_Wjets_mvis_Wjets    = path_sim + s_CR+"_Wjets_"+s_mvis+"_Wjets.root";
const TString CR_Wjets_mt_DY   = path_sim + s_CR+"_Wjets_"+s_mt+"_DY.root";
const TString CR_Wjets_mt_TT    = path_sim + s_CR+"_Wjets_"+s_mt+"_TT.root";
const TString CR_Wjets_mt_QCD      = path_sim + s_CR+"_Wjets_"+s_mt+"_QCD.root";

const TString CR_DY_mt_Wjets   = path_sim + s_CR+"_DY_"+s_mt+"_Wjets.root";
const TString CR_DY_mt_DY  = path_sim + s_CR+"_DY_"+s_mt+"_DY.root";
const TString CR_DY_mt_TT   = path_sim + s_CR+"_DY_"+s_mt+"_TT.root";
const TString CR_DY_mt_QCD     = path_sim + s_CR+"_DY_"+s_mt+"_QCD.root";

const TString CR_TT_mt_Wjets    = path_sim + s_CR+"_TT_"+s_mt+"_Wjets.root";
const TString CR_TT_mt_DY   = path_sim + s_CR+"_TT_"+s_mt+"_DY.root";
const TString CR_TT_mt_TT    = path_sim + s_CR+"_TT_"+s_mt+"_TT.root";
const TString CR_TT_mt_QCD      = path_sim + s_CR+"_TT_"+s_mt+"_QCD.root";

const TString CR_QCD_mt_Wjets      = path_sim + s_CR+"_QCD_"+s_mt+"_Wjets.root";
const TString CR_QCD_mt_DY     = path_sim + s_CR+"_QCD_"+s_mt+"_DY.root";
const TString CR_QCD_mt_TT      = path_sim + s_CR+"_QCD_"+s_mt+"_TT.root";
const TString CR_QCD_mt_QCD        = path_sim + s_CR+"_QCD_"+s_mt+"_QCD.root";

const TString CR_QCD_mvis_data_MCsubtracted     = path_sim+s_CR+"_QCD_"+s_mvis+"_data_MCsubtracted.root";
const TString CR_QCD_muiso_data_MCsubtracted     = path_sim+s_CR+"_QCD_muiso_data_MCsubtracted.root";
const TString CR_Wjets_mvis_data_MCsubtracted   = path_sim+s_CR+"_Wjets_"+s_mvis+"_data_MCsubtracted.root";
// Empty histograms as placeholders
const TString empty_mt="empty_"+s_SR+"_"+s_mt+".root";

// Signal region
const TString SR_MCsum         = path_sim+s_SR+"_"+s_MCsum;
const TString SR_MCsum_mt      = SR_MCsum+"_"+s_mt+".root";
const TString SR_MCsum_mvis    = SR_MCsum+"_"+s_mvis+".root";
const TString SR_MCsum_pt      = SR_MCsum+"_"+s_pt+".root";

const TString SR_MCsum_woQCD       = path_sim+s_SR+"_"+s_MCsum+"_woQCD";
const TString SR_MCsum_woQCD_mt    = SR_MCsum_woQCD+"_"+s_mt+".root";
const TString SR_MCsum_woQCD_mvis  = SR_MCsum_woQCD+"_"+s_mvis+".root";
const TString SR_MCsum_woQCD_pt    = SR_MCsum_woQCD+"_"+s_pt+".root";

const TString SR_data       = path_sim+s_SR+"_data";
const TString SR_data_mt    = SR_data+"_"+s_mt+".root";
const TString SR_data_mvis  = SR_data+"_"+s_mvis+".root";
const TString SR_data_pt    = SR_data+"_"+s_pt+".root";

const TString SS_SR_data       = path_sim+s_SS_SR+"_data";
const TString SS_SR_data_mt    = SS_SR_data+"_"+s_mt+".root";
const TString SS_SR_data_mvis  = SS_SR_data+"_"+s_mvis+".root";
const TString SS_SR_data_pt    = SS_SR_data+"_"+s_pt+".root";

// x Axis label
const TString labelMt="m_{T} [GeV]";
const TString labelMvis="m_{vis} [GeV]";
const TString labelPt="p_{T} [GeV]";
const TString labelIso="rel. muon isolation";
const TString labelNb="number of b-tags";
const TString labelDRb="#Delta R(#tau,b)";

// Binning constants
const Double_t Mt_cuts_Wjets[] = {0.};
const Double_t Mt_cuts_DY[]    = {0.};
const Double_t Mt_cuts_TT[] = {0.};
const Double_t Mt_cuts_QCD[]   = {0.};

const Int_t N_m_Wjets = sizeof(Mt_cuts_Wjets)/sizeof(Double_t);
const Int_t N_m_DY = sizeof(Mt_cuts_DY)/sizeof(Double_t);
const Int_t N_m_TT = sizeof(Mt_cuts_TT)/sizeof(Double_t);
const Int_t N_m_QCD = sizeof(Mt_cuts_QCD)/sizeof(Double_t);

/*
Double_t Pt_cuts_Wjets[] = {20.,30.,40.,60.,80.,100.,150.};
Double_t Pt_cuts_DY[]    = {20.,30.,40.,60.,80.,100.,150.};
Double_t Pt_cuts_TT[] = {20.,30.,40.,60.,80.,100.,150.};
Double_t Pt_cuts_QCD[]   = {20.,30.,40.,60.,80.,100.,150.};
*/

const Double_t Pt_cuts_Wjets[] = {20.,25.,30.,40.};//lower boundaries of the pt bins, there are no data with pt<20.
const Double_t Pt_cuts_DY[]    = {20.,25.,30.,40.};
const Double_t Pt_cuts_TT[]    = {20.,25.,30.,40.}; //default!
const Double_t Pt_cuts_QCD[]   = {20.,25.,30.,40.};

/*const Double_t Pt_cuts_Wjets[] = {20.,25.,30.,40.,60};//lower boundaries of the pt bins, there are no data with pt<20.
const Double_t Pt_cuts_DY[]    = {20.,25.,30.,40.,60.};
const Double_t Pt_cuts_TT[]    = {20.,25.,30.,40.,60.}; //default!
const Double_t Pt_cuts_QCD[]   = {20.,25.,30.,40.,60.};*/

const Int_t N_p_Wjets = sizeof(Pt_cuts_Wjets)/sizeof(Double_t);
const Int_t N_p_DY = sizeof(Pt_cuts_DY)/sizeof(Double_t);
const Int_t N_p_TT = sizeof(Pt_cuts_TT)/sizeof(Double_t);
const Int_t N_p_QCD = sizeof(Pt_cuts_QCD)/sizeof(Double_t);

const Double_t Eta_cuts_Wjets[] = {0.};//these are the lower boundaries of the |eta| bins
const Double_t Eta_cuts_DY[]    = {0.};
const Double_t Eta_cuts_TT[] = {0.};
const Double_t Eta_cuts_QCD[]   = {0.};

const Int_t N_e_Wjets = sizeof(Eta_cuts_Wjets)/sizeof(Double_t);
const Int_t N_e_DY = sizeof(Eta_cuts_DY)/sizeof(Double_t);
const Int_t N_e_TT = sizeof(Eta_cuts_TT)/sizeof(Double_t);
const Int_t N_e_QCD = sizeof(Eta_cuts_QCD)/sizeof(Double_t);

const Int_t Decay_cuts_Wjets[] = {0,5};//normally 0,5
const Int_t Decay_cuts_DY[]    = {0,5};
const Int_t Decay_cuts_TT[] = {0,5};
const Int_t Decay_cuts_QCD[]   = {0,5};

const Int_t N_t_Wjets = sizeof(Decay_cuts_Wjets)/sizeof(Int_t);
const Int_t N_t_DY = sizeof(Decay_cuts_DY)/sizeof(Int_t);
const Int_t N_t_TT = sizeof(Decay_cuts_TT)/sizeof(Int_t);
const Int_t N_t_QCD = sizeof(Decay_cuts_QCD)/sizeof(Int_t);

const Int_t Njet_cuts_Wjets[] = {0,1};
const Int_t Njet_cuts_DY[] = {0,1};
const Int_t Njet_cuts_TT[] = {0};
const Int_t Njet_cuts_QCD[] = {0,1};

/*const Int_t Njet_cuts_Wjets[] = {0};
const Int_t Njet_cuts_DY[] = {0};
const Int_t Njet_cuts_TT[] = {0};
const Int_t Njet_cuts_QCD[] = {0};*/

const Int_t N_j_Wjets = sizeof(Njet_cuts_Wjets)/sizeof(Int_t);
const Int_t N_j_DY = sizeof(Njet_cuts_DY)/sizeof(Int_t);
const Int_t N_j_TT = sizeof(Njet_cuts_TT)/sizeof(Int_t);
const Int_t N_j_QCD = sizeof(Njet_cuts_QCD)/sizeof(Int_t);

const Int_t nbins_mt=25;     const Double_t hist_min_mt=0.;   const Double_t hist_max_mt=250.;
const Int_t nbins_mvis=25;   const Double_t hist_min_mvis=0.; const Double_t hist_max_mvis=250.;
const Int_t nbins_pt=25;     const Double_t hist_min_pt=20.;  const Double_t hist_max_pt=100.;

//binning constants: weight
const Double_t w_mt_v[]={0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250};
const Int_t    w_mt_n=(sizeof(w_mt_v)/sizeof(Double_t)) -1;

const Double_t w_mvis_v[]={0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,225,250,300,350,450};
const Int_t w_mvis_n=(sizeof(w_mvis_v)/sizeof(Double_t)) -1;

const Double_t w_zpt_v[]={0,10,20,30,40,50,60,80,120,200};
const Int_t w_zpt_n=(sizeof(w_zpt_v)/sizeof(Double_t)) -1;

const Double_t w_muiso_v[]={0.00,0.02,0.05,0.1,0.15,0.2,0.25,0.3,0.4,0.5,0.7};
//const Double_t w_muiso_v[]={0.00,0.05,0.1,0.15};
const Int_t w_muiso_n=(sizeof(w_muiso_v)/sizeof(Double_t)) -1;

const Int_t    w_dm_v[]={0,4,15};
//const Int_t    w_dm_v[]={0,15}; //no binning in dm
const Int_t    w_dm_n=sizeof(w_dm_v)/sizeof(Int_t) -1;

const Int_t    w_njets_v[]={0,1,10};
const Int_t    w_njets_n=sizeof(w_njets_v)/sizeof(Int_t) -1;

const Int_t nbins_weight=w_mt_n*w_dm_n; const Double_t min_weight=-0.5;    const Double_t max_weight=nbins_weight-0.5;

const unsigned nVAR=4;
const Int_t nbins[nVAR]={nbins_mt,nbins_mvis,nbins_pt,w_muiso_n};
const Double_t hist_min[nVAR]={hist_min_mt,hist_min_mvis,hist_min_pt,hist_min_pt}; //pt bin is placeholder for muiso
const Double_t hist_max[nVAR]={hist_max_mt,hist_max_mvis,hist_max_pt,hist_max_pt}; //pt bin is placeholder for muiso
const TString tvar[nVAR]={s_mt,s_mvis,s_pt,s_muiso};
const TString tvar_l[nVAR]={"m_{T} [GeV]","m_{vis} [GeV]","p_{T} [GeV]", "#mu_{iso}"};



//plotting constants
//const Double_t p_mt_v[]={0,10,20,30,40,50,60,70,150,250};
const Double_t p_mt_v[]={0,50,70,80,90,100,120,140,180,250};
const Int_t    p_mt_n=(sizeof(p_mt_v)/sizeof(Double_t)) -1;

const Double_t p_mvis_v[]={0,50,75,100,200};
const Int_t    p_mvis_n=(sizeof(p_mvis_v)/sizeof(Double_t)) -1;

const Double_t p_iso_v[]={0.00, 0.025, 0.050, 0.075, 0.100, 0.150, 0.200, 0.300, 0.500, 10.000};
const Int_t    p_iso_n=(sizeof(p_iso_v)/sizeof(Double_t)) -1;

const Double_t p_nb_v[]={-0.5 , 0.5 , 1.5 , 2.5 , 9};
const Int_t    p_nb_n=(sizeof(p_nb_v)/sizeof(Double_t)) -1;

const Double_t p_drb_v[]={0.0 , 0.05 , 0.2 , 1.0 , 5.0};
const Int_t    p_drb_n=(sizeof(p_drb_v)/sizeof(Double_t)) -1;

const Double_t p_absdeta_v[]={0.,0.5,0.75,1.,1.5};
const Int_t    p_absdeta_n=(sizeof(p_absdeta_v)/sizeof(Double_t)) -1;

const Double_t p_njets_v[]={-0.5,0.5,1.5,2.5,3.5};
const Int_t    p_njets_n=(sizeof(p_njets_v)/sizeof(Double_t)) -1;

const Double_t p_nbjets_v[]={-0.5,0.5};
const Int_t    p_nbjets_n=(sizeof(p_nbjets_v)/sizeof(Double_t)) -1;



//const TString corr_histo_file_name=FF_DY_J_only_mtll_CR;
//const Int_t   corr_nbin=p_mt_n;
//const Int_t   corr_norm=8;

//const double global_tmp;
const TString sNum[]={"0","1","2","3","4","5","6","7","8","9"};

// Plotting colors
const Int_t color_Wjets=kRed;
const Int_t color_DY_J=kBlue;
const Int_t color_DY_TT=kYellow;
const Int_t color_DY_L=kViolet;
const Int_t color_TT_J=kGreen;
const Int_t color_TT_T=kGreen+2;
const Int_t color_TT_L=kGreen-1;
const Int_t color_sum=kMagenta;
const Int_t color_QCD=kCyan;

const int nSAMPLES=11;
const int nSAMPLES_COMP=7;
static const TString vlabel[nSAMPLES]={"W+jets","ttJ (j#rightarrow#tau)","ttT (#tau#rightarrow#tau)","ttL (l#rightarrow#tau)","ZJ (j#rightarrow#tau)","ZTT (#tau#rightarrow#tau)","ZL (l#rightarrow#tau)","QCD","VV (j#rightarrow#tau)", "VV (#tau#rightarrow#tau)","VV (l#rightarrow#tau)"};
static const TString vlabel_compare[nSAMPLES_COMP]={"W+jets","tt","ZJ (j#rightarrow#tau)","ZTT (#tau#rightarrow#tau)","ZL (l#rightarrow#tau)","VV","QCD"};
static const TString vlabel_compare2[nSAMPLES_COMP-3]={"W+jets","tt","ZJ","QCD"};
static const TString vlabel_w_ff[nSAMPLES-3]={"ttT (#tau#rightarrow#tau)","ttL (l#rightarrow#tau)","ZTT (#tau#rightarrow#tau)","ZL (l#rightarrow#tau)","jet #rightarrow #tau fakes","VV (#tau#rightarrow#tau)","VV (l#rightarrow#tau)"};
static const TString vlabel_check[nSAMPLES-6]={"W+jets","QCD","ttJ (j#rightarrow#tau)","ZJ   (j#rightarrow#tau)"};
static const TString vname[nSAMPLES]= {"Wjets" ,"ttJ"                   ,"ttT"                      ,"ttL"                   ,"ZJ"                     ,"ZTT"                      ,"ZL"                     ,"QCD", "VVT", "VVL"};
static const TString vsuff[nSAMPLES]= {"Wjets" ,"TT_J"                  ,"TT_T"                     ,"TT_L"                  ,"DY_J"                   ,"DY_TT"                    ,"DY_L"                   ,"QCD", "VV_J", "VV_T", "VV_L"};
const Int_t vcolor[nSAMPLES]=         {kRed    ,kGreen                  ,kGreen+2                   ,kGreen-1                ,kBlue                    ,kYellow                    ,kViolet                  ,kCyan, kYellow-5, kYellow-6};
const Int_t vcolor_compare[nSAMPLES_COMP]= {kRed    ,kGreen                  ,kBlue                      ,kYellow                 ,kViolet                  ,kYellow-5                  ,kCyan};
const Int_t vcolor_compare2[nSAMPLES_COMP-3]= {kRed    ,kGreen                  ,kBlue                      ,kCyan};
const Int_t vcolor_run1[nSAMPLES-1]=  {kRed    ,kGreen                  ,kGreen+2                   ,kGreen-1                ,kBlue                    ,kViolet                  ,kCyan, kYellow-5, kYellow-6};
const Int_t vcolor_FF[nSAMPLES-3]=  {kGreen+2                  ,kGreen-1                ,kYellow                    ,kViolet                  ,kCyan, kYellow-5, kYellow-6};
const Int_t vcolor_check[nSAMPLES-6]=  {kRed                  ,kCyan                ,kBlue                    ,kGreen};
const int smap[nSAMPLES]=      {0,2,6,7,1,4,5,3,8,9};
const int smap_noqcd[nSAMPLES-1]={0,2,5,6,1,3,4,7,8};

//int smap[]=      {0,2,6,7,1,4,5,3};
//int smap_noqcd[]={0,2,6,1,4,5,3};

const unsigned n_ff=4;
const Int_t vlabel_i_ff[n_ff]={0,4,1,7};

const unsigned NC=8;
const TString c_text[NC]={"1p","3p","pt1","pt2","pt3","eta1","eta2","eta3"};
const Int_t c_cuts[NC]={NP1,NP3,PT1,PT2,PT3,ETA1,ETA2,ETA3};

static const std::vector<TString> empty_vec_tstring;

const Int_t nCAT=8;
const TString categories[nCAT] = { "_0jet", "_1jet", "_1jetZ050", "_1jetZ50100", "_1jetZ100", "_2jet", "_2jetVBF", "_anyb"};
const Int_t catMode[nCAT] = {_0JET, _1JET, _1JETZ050, _1JETZ50100, _1JETZ100, _2JET, _2JETVBF, _ANYB };

//const Int_t nCAT=4;
//const TString categories[nCAT] = { "_0jet", "_1jet", "_2jet", "_anyb"};
//const Int_t catMode[nCAT] = {_0JET, _1JET, _2JET, _ANYB };
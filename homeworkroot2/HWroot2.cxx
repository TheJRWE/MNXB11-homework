#include "HWroot2.h"
ClassImp(HWroot2)

HWroot2::HWroot2() :
    px(0.0), py(0.0), pz(0.0)
{
    P = CalcP();
}

HWroot2::HWroot2(Double_t pxVal, Double_t pyVal, Double_t pzVal) :
    px(pxVal), py(pyVal), pz(pzVal)
{
    P = CalcP();
}

HWroot2::~HWroot2(){

}

Double_t HWroot2::CalcP() const {
    return TMath::Sqrt(px*px + py*py + pz*pz);
}

Double_t HWroot2::GetPx() const {
    return px;
}

Double_t HWroot2::GetPy() const {
    return py;
}

Double_t HWroot2::GetPz() const {
    return pz;
}

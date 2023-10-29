#ifndef __HWroot2__
#define __HWroot2__

#include <TObject.h>
#include <TMath.h>

class HWroot2 : public TObject {
    public:
        HWroot2();
        HWroot2(Double_t pxVal, Double_t pyVal, Double_t pzVal);
        virtual ~HWroot2();

        Double_t CalcP() const;
        Double_t GetPx() const;
        Double_t GetPy() const;
        Double_t GetPz() const;

    private:
        Double_t px;
        Double_t py;
        Double_t pz;
        Double_t P;


    ClassDef(HWroot2, 1);
};


#endif // __HWroot2__
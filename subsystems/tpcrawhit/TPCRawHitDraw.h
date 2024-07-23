#ifndef TPC_TPCDRAW_H__
#define TPC_TPCDRAW_H__

#include <qahtml/QADraw.h>

#include <vector>

class QADB;
class QADBVar;
class TCanvas;
class TGraphErrors;
class TPad;
class TH1F;
class TH2F;

class TPCRawHitDraw : public QADraw
{
 public: 
  TPCRawHitDraw(const std::string &name = "TpcRawHitQA");
  ~TPCRawHitDraw() override;

  int Draw(const std::string &what = "ALL") override;
  int MakeHtml(const std::string &what = "ALL") override;
  int DBVarInit();

 private:
  int MakeCanvas(const std::string &name, int num);
  int DrawSectorInfo();
  TCanvas *TC[9]{};
  TPad *transparent[9]{};
  TPad *Pad[9][6]{};
  const char *histprefix;
};

#endif

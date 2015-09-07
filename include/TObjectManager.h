#ifndef _TOBJECTMANAGER_H_
#define _TOBJECTMANAGER_H_

#include <map>
#include <vector>

#include "TQObject.h"
#include "TDirectory.h"
#include "TFile.h"

//class TObjectManager : public TDirectory, public TQObject {
class TObjectManager : public TFile, public TQObject {
public:
  static void Get(const char* name, Option_t *opt="update");
  virtual ~TObjectManager();

  virtual void Add(TObject* obj, Bool_t replace = kFALSE);
  virtual void Append(TObject* obj, Bool_t replace = kFALSE);

  virtual void Print(Option_t* opt = "") const;

  void ObjectAppended(TObject* obj); //*SIGNAL*

  void AddRelationship(TObject* parent, TObject* child);

  //virtual void RecursiveRemove(TObject* obj);

  static TObjectManager *Open(const char *fname,Option_t *opt="read");
  static TList *GetListOfManagers() { return &objectmanagers; }
  TObjectManager *cd();

private:
  static TList objectmanagers;
  TObjectManager(const char* name, const char* title);
  
  typedef std::map<TObject*,std::vector<TObject*> > ParentChildMap;
  ParentChildMap fParentChildren;
  void SaveParent(TObject*);


  ClassDef(TObjectManager, 0);
};

extern TObjectManager* gManager;

#endif /* _TOBJECTMANAGER_H_ */

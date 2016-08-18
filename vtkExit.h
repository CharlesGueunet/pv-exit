// .NAME vtkExit - save a dataset on disc
// .SECTION Description
// vtkExit is a filter to save a dataset on the disk
// while using it. A typical example is saving a plane with
// random scalar-field when tracking a bug on a plugin.
// It will allow you to keep the problematic data-set.

#ifndef __vtkGenericWriter_h
#define __vtkGenericWriter_h

#include "vtkDataSetAlgorithm.h"

class VTK_EXPORT vtkExit : public vtkDataSetAlgorithm
{
public:
  static vtkExit* New();
  vtkTypeMacro(vtkExit, vtkDataSetAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent);

  vtkSetMacro(Quit, bool);
  vtkGetMacro(Quit, bool);

protected:
  vtkExit();
  ~vtkExit();

  // VTK Interface

  virtual int FillOutputPortInformation(int port, vtkInformation* info);

  int RequestData(vtkInformation* request,
                  vtkInformationVector** inputVector,
                  vtkInformationVector* outputVector);

  // fields

  bool Quit;

private:
  vtkExit(const vtkExit&);  // Not implemented.
  void operator=(const vtkExit&);  // Not implemented.
};

#endif

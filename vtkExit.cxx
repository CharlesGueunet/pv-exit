#include "vtkExit.h"

#include "vtkDataSet.h"
#include "vtkInformation.h"
#include "vtkInformationVector.h"
#include "vtkObjectFactory.h"

vtkStandardNewMacro(vtkExit);

// Public
// {{{

//----------------------------------------------------------------------------
void vtkExit::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}

// }}}
// Protected
// {{{

//----------------------------------------------------------------------------
vtkExit::vtkExit()
{
  this->Quit = false;
}

//----------------------------------------------------------------------------
vtkExit::~vtkExit()
{
}

int vtkExit::FillOutputPortInformation(int port, vtkInformation* info)
{
  switch (port)
    {
    case 0:
      info->Set(vtkDataObject::DATA_TYPE_NAME(), "vtkDataSet");
      break;
    default:
      info->Set(vtkDataObject::DATA_TYPE_NAME(), "vtkDataObject");
      break;
    }

  return 1;
}

int vtkExit::RequestData(vtkInformation*        request,
                          vtkInformationVector** inputVector,
                          vtkInformationVector*  outputVector)
{

  vtkDataSet* inputData = vtkDataSet::GetData(inputVector[0]);

  vtkInformation* outputInfo = outputVector->GetInformationObject(0);
  vtkDataSet*     outputData =
      vtkDataSet::SafeDownCast(outputInfo->Get(vtkDataObject::DATA_OBJECT()));
  // this plugin does not modify the input
  outputData->ShallowCopy(inputData);

  if(Quit) exit(0);

  return 1;
}

// }}}

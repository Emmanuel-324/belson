//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "belsonTestApp.h"
#include "belsonApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
belsonTestApp::validParams()
{
  InputParameters params = belsonApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

belsonTestApp::belsonTestApp(InputParameters parameters) : MooseApp(parameters)
{
  belsonTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

belsonTestApp::~belsonTestApp() {}

void
belsonTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  belsonApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"belsonTestApp"});
    Registry::registerActionsTo(af, {"belsonTestApp"});
  }
}

void
belsonTestApp::registerApps()
{
  registerApp(belsonApp);
  registerApp(belsonTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
belsonTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  belsonTestApp::registerAll(f, af, s);
}
extern "C" void
belsonTestApp__registerApps()
{
  belsonTestApp::registerApps();
}

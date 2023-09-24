#include "belsonApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
belsonApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

belsonApp::belsonApp(InputParameters parameters) : MooseApp(parameters)
{
  belsonApp::registerAll(_factory, _action_factory, _syntax);
}

belsonApp::~belsonApp() {}

void 
belsonApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<belsonApp>(f, af, s);
  Registry::registerObjectsTo(f, {"belsonApp"});
  Registry::registerActionsTo(af, {"belsonApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
belsonApp::registerApps()
{
  registerApp(belsonApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
belsonApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  belsonApp::registerAll(f, af, s);
}
extern "C" void
belsonApp__registerApps()
{
  belsonApp::registerApps();
}

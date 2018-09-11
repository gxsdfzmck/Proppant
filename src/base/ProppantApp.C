#include "ProppantApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<ProppantApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

ProppantApp::ProppantApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  ProppantApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  ProppantApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  ProppantApp::registerExecFlags(_factory);
}

ProppantApp::~ProppantApp() {}

void
ProppantApp::registerApps()
{
  registerApp(ProppantApp);
}

void
ProppantApp::registerObjects(Factory & factory)
{
    Registry::registerObjectsTo(factory, {"ProppantApp"});
}

void
ProppantApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"ProppantApp"});

  /* Uncomment Syntax parameter and register your new production objects here! */
}

void
ProppantApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
ProppantApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
ProppantApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
ProppantApp__registerApps()
{
  ProppantApp::registerApps();
}

extern "C" void
ProppantApp__registerObjects(Factory & factory)
{
  ProppantApp::registerObjects(factory);
}

extern "C" void
ProppantApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  ProppantApp::associateSyntax(syntax, action_factory);
}

extern "C" void
ProppantApp__registerExecFlags(Factory & factory)
{
  ProppantApp::registerExecFlags(factory);
}

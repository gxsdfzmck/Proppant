//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "ProppantTestApp.h"
#include "ProppantApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<ProppantTestApp>()
{
  InputParameters params = validParams<ProppantApp>();
  return params;
}

ProppantTestApp::ProppantTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  ProppantApp::registerObjectDepends(_factory);
  ProppantApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  ProppantApp::associateSyntaxDepends(_syntax, _action_factory);
  ProppantApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  ProppantApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    ProppantTestApp::registerObjects(_factory);
    ProppantTestApp::associateSyntax(_syntax, _action_factory);
    ProppantTestApp::registerExecFlags(_factory);
  }
}

ProppantTestApp::~ProppantTestApp() {}

void
ProppantTestApp::registerApps()
{
  registerApp(ProppantApp);
  registerApp(ProppantTestApp);
}

void
ProppantTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
ProppantTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
ProppantTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
ProppantTestApp__registerApps()
{
  ProppantTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
ProppantTestApp__registerObjects(Factory & factory)
{
  ProppantTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
ProppantTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  ProppantTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
ProppantTestApp__registerExecFlags(Factory & factory)
{
  ProppantTestApp::registerExecFlags(factory);
}

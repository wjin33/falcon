//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "GeneralPostprocessor.h"

class PorousFlowSteadyStateTerminator;

///template <>
///InputParameters validParams<PorousFlowSteadyStateDetection>();

/**
 * Computes the relative change rate in a post-processor value.
 */
class PorousFlowSteadyStateTerminator : public GeneralPostprocessor
{
public:
  static InputParameters validParams();

  PorousFlowSteadyStateTerminator(const InputParameters & parameters);

  virtual void initialize() override;
  virtual void execute() override;
  virtual Real getValue() const override;

protected:
  /// current post-processor value
  const PostprocessorValue & _pps_value;

  /// current time value
  const PostprocessorValue & _pps_t;

  Real _steady_state_start_time;
  Real _steady_state_end_time;
  Real _steady_state_relative_diff;

};

/*
 * Copyright (C) 2011 Georgia Institute of Technology, University of Utah,
 * Weill Cornell Medical College
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * This is a template implementation file for a user module derived from
 * DefaultGUIModel with a custom GUI.
 */

#include "neun-cgc-for-rtxi.h"
#include <iostream>
#include <main_window.h>

extern "C" Plugin::Object*
createRTXIPlugin(void)
{
  return new NeunCgcForRtxi();
}


Neuron NeunCgcForRtxi::initNeuron()
{

  // InputParser yaml_parser(INIT_YAML);

  Neuron::ConstructorArgs args;  // t, tau_p, tau_q, g_eca, g_ecs, n_parameters

  // std::map<string,double> v_args = yaml_parser.parse_file();

  // std::vector<std::string> param_names = Neuron::ParamNames();

  // for(int i=0; i < Neuron::n_parameters; i++)
  // {
  //   args.params[i] = v_args[param_names[i]];
  // }

  // Set the parameter values
  //TODO fix reading by YAML
    args.params[Neuron::Ga] = 18.82;
    args.params[Neuron::Gd] = 1.2;
    args.params[Neuron::Ghva] = 1.03;
    args.params[Neuron::Glva] = 0.01;
    args.params[Neuron::Gnap] = 0.44;
    args.params[Neuron::Gnat] = 1.68;
    args.params[Neuron::Ia] = 3.0;
    args.params[Neuron::Id] = 3.0;
    args.params[Neuron::Ihva] = 3.0;
    args.params[Neuron::Ilva] = 3.0;
    args.params[Neuron::Inap] = 3.0;
    args.params[Neuron::Inat] = 3.0;
    args.params[Neuron::Q10_Ga] = 3.0;
    args.params[Neuron::Q10_Gd] = 3.0;
    args.params[Neuron::Q10_Ghva] = 3.0;
    args.params[Neuron::Q10_Glva] = 3.0;
    args.params[Neuron::Q10_Gnap] = 3.0;
    args.params[Neuron::Q10_Gnat] = 3.0;
    args.params[Neuron::Q10_a] = 3.0;
    args.params[Neuron::Q10_b] = 3.0;
    args.params[Neuron::Q10_e] = 3.0;
    args.params[Neuron::Q10_f] = 3.0;
    args.params[Neuron::Q10_h] = 3.0;
    args.params[Neuron::Q10_n] = 3.0;
    args.params[Neuron::Q10_r] = 3.0;
    args.params[Neuron::Vh_c] = -41.35;
    args.params[Neuron::Vh_d] = -64.13;
    args.params[Neuron::Vh_m] = -35.2;
    args.params[Neuron::Vs_c] = 5.05;
    args.params[Neuron::Vs_d] = -4.03;
    args.params[Neuron::Vs_m] = 9.66;
    args.params[Neuron::cm] = 1.0;
    args.params[Neuron::delta_a] = 0.39;
    args.params[Neuron::delta_b] = 0.83;
    args.params[Neuron::delta_e] = 0.84;
    args.params[Neuron::delta_f] = 0.97;
    args.params[Neuron::delta_h] = 0.03;
    args.params[Neuron::delta_n] = 0.18;
    args.params[Neuron::delta_r] = 1.0;
    args.params[Neuron::diff_T] = 0.0;
    args.params[Neuron::dv] = 3.0;
    args.params[Neuron::gamma_T] = 0.05;
    args.params[Neuron::tau0_a] = 13.28;
    args.params[Neuron::tau0_b] = 226.75;
    args.params[Neuron::tau0_e] = 3.81;
    args.params[Neuron::tau0_f] = 34.68;
    args.params[Neuron::tau0_h] = 778.82;
    args.params[Neuron::tau0_n] = 14.52;
    args.params[Neuron::tau0_r] = 4.01;
    args.params[Neuron::vca] = 80.0;
    args.params[Neuron::vh_a] = -36.37;
    args.params[Neuron::vh_b] = -83.0;
    args.params[Neuron::vh_e] = -14.25;
    args.params[Neuron::vh_f] = -21.44;
    args.params[Neuron::vh_h] = -56.43;
    args.params[Neuron::vh_n] = -59.43;
    args.params[Neuron::vh_r] = -47.03;
    args.params[Neuron::vk] = -90.0;
    args.params[Neuron::vna] = 55.0;
    args.params[Neuron::vs_a] = 8.72;
    args.params[Neuron::vs_b] = -6.2;
    args.params[Neuron::vs_e] = 6.96;
    args.params[Neuron::vs_f] = -5.78;
    args.params[Neuron::vs_h] = -8.41;
    args.params[Neuron::vs_n] = 34.79;
    args.params[Neuron::vs_r] = 20.55;

  Neuron cgc(args);

  cgc.set(Neuron::v, v0);
  cgc.set(Neuron::h, 1 / (1 + exp( (args.params[Neuron::vh_h] - v0) / args.params[Neuron::vs_h])));
  cgc.set(Neuron::r, 1 / (1 + exp( (args.params[Neuron::vh_r] - v0) / args.params[Neuron::vs_r])));
  cgc.set(Neuron::a, 1 / (1 + exp( (args.params[Neuron::vh_a] - v0) / args.params[Neuron::vs_a])));
  cgc.set(Neuron::b, 1 / (1 + exp( (args.params[Neuron::vh_b] - v0) / args.params[Neuron::vs_b])));
  cgc.set(Neuron::n, 1 / (1 + exp( (args.params[Neuron::vh_n] - v0) / args.params[Neuron::vs_n])));
  cgc.set(Neuron::e, 1 / (1 + exp( (args.params[Neuron::vh_e] - v0) / args.params[Neuron::vs_e])));
  cgc.set(Neuron::f, 1 / (1 + exp( (args.params[Neuron::vh_f] - v0) / args.params[Neuron::vs_f])));
  printf("Neuron created");

  return cgc;
}

// DefaultGUIModel::variable_t vars[Neuron::n_parameters+1];
// DefaultGUIModel::variable_t * vars = (DefaultGUIModel::variable_t) malloc(sizeof(DefaultGUIModel::variable_t)*Neuron::n_parameters+1);
// std::vector<DefaultGUIModel::variable_t> vars;

// void NeunCgcForRtxi::initVars() {
  
//   std::vector<std::string> param_names = Neuron::ParamNames();
//   for (int i = 0; i < Neuron::n_parameters; i++) {
//     vars[i].name = param_names[i];
//     vars[i].description = "Tooltip description";
//     vars[i].flags = DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE;
//   }
//   int last = Neuron::n_parameters;
//   vars[last].name = "Voltage (mV)";
//   vars[last].description = "Voltage output simulated";
//   vars[last].flags = DefaultGUIModel::OUTPUT;
//   // std::vector<std::string> param_names = Neuron::ParamNames();
//   // vars.resize(Neuron::n_parameters + 1);
//   // for (int i = 0; i < Neuron::n_parameters; ++i) {
//   //   vars[i].name = param_names[i];
//   //   vars[i].description = "Tooltip description";
//   //   vars[i].flags = DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE;
//   // }

//   // int last = Neuron::n_parameters;
//   // vars[last].name = "Voltage (mV)";
//   // vars[last].description = "Voltage output simulated";
//   // vars[last].flags = DefaultGUIModel::OUTPUT;
// }




DefaultGUIModel::variable_t vars[] = {
// PARAMETERS

{"i_ext", "Fixed External current input to add", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"diff_T", "diff_T", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"cm", "cm", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"gamma_T", "gamma_T", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"vna", "vna", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"vk", "vk", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"vca", "vca", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Gnat", "Gnat", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Gnap", "Gnap", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Ga", "Ga", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Gd", "Gd", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Glva", "Glva", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Ghva", "Ghva", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Q10_Gnat", "Q10_Gnat", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Q10_Gnap", "Q10_Gnap", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Q10_Ga", "Q10_Ga", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Q10_Gd", "Q10_Gd", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Q10_Glva", "Q10_Glva", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Q10_Ghva", "Q10_Ghva", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"vh_h", "vh_h", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"vs_h", "vs_h", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"tau0_h", "tau0_h", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"delta_h", "delta_h", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Q10_h", "Q10_h", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"vh_r", "vh_r", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"vs_r", "vs_r", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"tau0_r", "tau0_r", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"delta_r", "delta_r", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Q10_r", "Q10_r", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"vh_a", "vh_a", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"vs_a", "vs_a", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"tau0_a", "tau0_a", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"delta_a", "delta_a", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Q10_a", "Q10_a", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"vh_b", "vh_b", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"vs_b", "vs_b", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"tau0_b", "tau0_b", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"delta_b", "delta_b", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Q10_b", "Q10_b", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"vh_n", "vh_n", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"vs_n", "vs_n", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"tau0_n", "tau0_n", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"delta_n", "delta_n", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Q10_n", "Q10_n", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"vh_e", "vh_e", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"vs_e", "vs_e", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"tau0_e", "tau0_e", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"delta_e", "delta_e", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Q10_e", "Q10_e", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"vh_f", "vh_f", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"vs_f", "vs_f", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"tau0_f", "tau0_f", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"delta_f", "delta_f", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Q10_f", "Q10_f", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Vh_m", "Vh_m", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Vs_m", "Vs_m", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Vh_c", "Vh_c", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Vs_c", "Vs_c", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Vh_d", "Vh_d", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Vs_d", "Vs_d", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"dv", "dv", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Inat", "Inat", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Inap", "Inap", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Ia", "Ia", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Id", "Id", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Ilva", "Ilva", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},
{"Ihva", "Ihva", DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE,},

//INPUTS
{"I_syn", "Synapse current input", DefaultGUIModel::INPUT,},

// OUTPUTS
{"Vm (mV)", "Simulated Voltage", DefaultGUIModel::OUTPUT,},
};

static size_t num_vars = sizeof(vars) / sizeof(DefaultGUIModel::variable_t);


// NeunCgcForRtxi::NeunCgcForRtxi(void)
//   : DefaultGUIModel("NeunCgcForRtxi", ::vars, ::num_vars),neuron(initNeuron())
// {


NeunCgcForRtxi::NeunCgcForRtxi(void)
  : DefaultGUIModel("NeunCgcForRtxi", ::vars, ::num_vars),neuron(initNeuron())
{
  
  // initVars();

  DefaultGUIModel::createGUI(vars, num_vars); // this is required to create the GUI


  setWhatsThis("<p><b>NeunCgcForRtxi:</b><br>QWhatsThis description.</p>");
  
  customizeGUI();
  initParameters();
  update(INIT); // this is optional, you may place initialization code directly
                // into the constructor
  refresh();    // this is required to update the GUI with parameter and state
                // values
  QTimer::singleShot(0, this, SLOT(resizeMe()));
}

NeunCgcForRtxi::~NeunCgcForRtxi(void)
{
}

void
NeunCgcForRtxi::execute(void)
{
  neuron.step(0.01);
  neuron.add_synaptic_input(i_ext);
  output(0) = neuron.get(Neuron::v) / 1000;

  return;
}

void
NeunCgcForRtxi::initParameters(void)
{

  // neuron = initNeuron();
  i_ext = 0.1;
  v0 = -65;
  diff_T = 0;
}

void
NeunCgcForRtxi::update(DefaultGUIModel::update_flags_t flag)
{
  switch (flag) {
    case INIT:
      period = RT::System::getInstance()->getPeriod() * 1e-6; // ms
      
      setParameter("i_ext", i_ext);

      param_names = Neuron::ParamNames();
      for (int i = 1; i < Neuron::n_parameters; i++) {
        vars[i].name = param_names[i];
    // Convert std::string to QString for setParameter
        QString paramName = QString::fromStdString(param_names[i]);
        double paramValue = static_cast<double>(
            neuron.get(static_cast<VavoulisCGCModelQ10<double>::parameter>(i))
        );
        setParameter(paramName, paramValue);
      }
      param_names_qt.clear();
      for (const auto& name : Neuron::ParamNames()) {
          param_names_qt.push_back(QString::fromStdString(name));
      }

      break;

    case MODIFY:
      i_ext = getParameter("i_ext").toDouble();

      for (int i = 0; i < Neuron::n_parameters; i++) {
        double value = getParameter(param_names_qt[i]).toDouble();
        neuron.set(static_cast<VavoulisCGCModelQ10<double>::parameter>(i), value);
    }
      break;

    case UNPAUSE:
      break;

    case PAUSE:
      break;

    case PERIOD:
      period = RT::System::getInstance()->getPeriod() * 1e-6; // ms
      break;

    default:
      break;
  }
}

void
NeunCgcForRtxi::customizeGUI(void)
{
  QGridLayout* customlayout = DefaultGUIModel::getLayout();

  QGroupBox* button_group = new QGroupBox;

  QPushButton* abutton = new QPushButton("Reset initial");
  QPushButton* bbutton = new QPushButton("Button B");
  QHBoxLayout* button_layout = new QHBoxLayout;
  button_group->setLayout(button_layout);
  button_layout->addWidget(abutton);
  button_layout->addWidget(bbutton);
  QObject::connect(abutton, SIGNAL(clicked()), this, SLOT(aBttn_event()));
  QObject::connect(bbutton, SIGNAL(clicked()), this, SLOT(bBttn_event()));

  customlayout->addWidget(button_group, 0, 0);
  setLayout(customlayout);
}

// functions designated as Qt slots are implemented as regular C++ functions
void
NeunCgcForRtxi::aBttn_event(void)
{ 
    initParameters();

}

void
NeunCgcForRtxi::bBttn_event(void)
{
}

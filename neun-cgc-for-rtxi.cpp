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
    args.params[Neuron::t_scale] = 1;
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

DefaultGUIModel::variable_t vars[Neuron::n_parameters+11];

DefaultGUIModel::variable_t * NeunCgcForRtxi::initVars() {
  vars[0].name = "step";
  vars[0].description = "Integration step";
  vars[0].flags = DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE;
  vars[1].name = "Iext";
  vars[1].description = "constant external input";
  vars[1].flags = DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE;

  std::vector<std::string> param_names = Neuron::ParamNames();
  for (int i = 2; i < Neuron::n_parameters+2; i++) {
    vars[i].name = param_names[i-2];
    vars[i].description = param_names[i-2];
    vars[i].flags = DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE;
  }
  int last = Neuron::n_parameters+1;
  vars[last].name = "Voltage (mV)";
  vars[last].description = "Voltage output simulated";
  vars[last].flags = DefaultGUIModel::OUTPUT;

  //TODO generalize
  last++;

  vars[last].name = "Ia"; vars[last].description = "Ia current"; vars[last].flags = DefaultGUIModel::OUTPUT;
  last++;
  
  vars[last].name = "Id"; vars[last].description = "Id current"; vars[last].flags = DefaultGUIModel::OUTPUT;
  last++;

  vars[last].name = "Ihva"; vars[last].description = "Ihva current"; vars[last].flags = DefaultGUIModel::OUTPUT;
  last++;

  vars[last].name = "Ilva"; vars[last].description = "Ilva current"; vars[last].flags = DefaultGUIModel::OUTPUT;
  last++;

  vars[last].name = "Inap"; vars[last].description = "Inap current"; vars[last].flags = DefaultGUIModel::OUTPUT;
  last++;

  vars[last].name = "Inat"; vars[last].description = "Inat current"; vars[last].flags = DefaultGUIModel::OUTPUT;
  last++;

  vars[last].name = "Isyn"; vars[last].description = "Synaptic input"; vars[last].flags = DefaultGUIModel::INPUT;

  return vars;
}

static size_t num_vars = sizeof(vars) / sizeof(DefaultGUIModel::variable_t);
NeunCgcForRtxi::NeunCgcForRtxi()
  : DefaultGUIModel("NeunCgcForRtxi", initVars(), num_vars),
    neuron(initNeuron())
{

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
  neuron.step(step);
  neuron.add_synaptic_input(i_ext);

  neuron.add_synaptic_input(input(0));

  output(0) = neuron.get(Neuron::v) / 1000;

  // TODO generalize
  output(1) = neuron.get(Neuron::Ia);
  output(2) = neuron.get(Neuron::Id);
  output(3) = neuron.get(Neuron::Ihva);
  output(4) = neuron.get(Neuron::Ilva);
  output(5) = neuron.get(Neuron::Inap);
  output(6) = neuron.get(Neuron::Inat);
  

  return;
}

void
NeunCgcForRtxi::initParameters(void)
{

  // neuron = initNeuron();
  i_ext = 0.1;
  v0 = -65;
  diff_T = 0;
  step = 0.01;

  //TODO fix reading by YAML
  neuron.set(Neuron::Ga, 18.82);
  neuron.set(Neuron::Gd, 1.2);
  neuron.set(Neuron::Ghva, 1.03);
  neuron.set(Neuron::Glva, 0.01);
  neuron.set(Neuron::Gnap, 0.44);
  neuron.set(Neuron::Gnat, 1.68);
  neuron.set(Neuron::Ia, 3.0);
  neuron.set(Neuron::Id, 3.0);
  neuron.set(Neuron::Ihva, 3.0);
  neuron.set(Neuron::Ilva, 3.0);
  neuron.set(Neuron::Inap, 3.0);
  neuron.set(Neuron::Inat, 3.0);
  neuron.set(Neuron::Q10_Ga, 3.0);
  neuron.set(Neuron::Q10_Gd, 3.0);
  neuron.set(Neuron::Q10_Ghva, 3.0);
  neuron.set(Neuron::Q10_Glva, 3.0);
  neuron.set(Neuron::Q10_Gnap, 3.0);
  neuron.set(Neuron::Q10_Gnat, 3.0);
  neuron.set(Neuron::Q10_a, 3.0);
  neuron.set(Neuron::Q10_b, 3.0);
  neuron.set(Neuron::Q10_e, 3.0);
  neuron.set(Neuron::Q10_f, 3.0);
  neuron.set(Neuron::Q10_h, 3.0);
  neuron.set(Neuron::Q10_n, 3.0);
  neuron.set(Neuron::Q10_r, 3.0);
  neuron.set(Neuron::Vh_c, -41.35);
  neuron.set(Neuron::Vh_d, -64.13);
  neuron.set(Neuron::Vh_m, -35.2);
  neuron.set(Neuron::Vs_c, 5.05);
  neuron.set(Neuron::Vs_d, -4.03);
  neuron.set(Neuron::Vs_m, 9.66);
  neuron.set(Neuron::cm, 1.0);
  neuron.set(Neuron::delta_a, 0.39);
  neuron.set(Neuron::delta_b, 0.83);
  neuron.set(Neuron::delta_e, 0.84);
  neuron.set(Neuron::delta_f, 0.97);
  neuron.set(Neuron::delta_h, 0.03);
  neuron.set(Neuron::delta_n, 0.18);
  neuron.set(Neuron::delta_r, 1.0);
  neuron.set(Neuron::diff_T, 0.0);
  neuron.set(Neuron::dv, 3.0);
  neuron.set(Neuron::gamma_T, 0.05);
  neuron.set(Neuron::tau0_a, 13.28);
  neuron.set(Neuron::tau0_b, 226.75);
  neuron.set(Neuron::tau0_e, 3.81);
  neuron.set(Neuron::tau0_f, 34.68);
  neuron.set(Neuron::tau0_h, 778.82);
  neuron.set(Neuron::tau0_n, 14.52);
  neuron.set(Neuron::tau0_r, 4.01);
  neuron.set(Neuron::vca, 80.0);
  neuron.set(Neuron::vh_a, -36.37);
  neuron.set(Neuron::vh_b, -83.0);
  neuron.set(Neuron::vh_e, -14.25);
  neuron.set(Neuron::vh_f, -21.44);
  neuron.set(Neuron::vh_h, -56.43);
  neuron.set(Neuron::vh_n, -59.43);
  neuron.set(Neuron::vh_r, -47.03);
  neuron.set(Neuron::vk, -90.0);
  neuron.set(Neuron::vna, 55.0);
  neuron.set(Neuron::vs_a, 8.72);
  neuron.set(Neuron::vs_b, -6.2);
  neuron.set(Neuron::vs_e, 6.96);
  neuron.set(Neuron::vs_f, -5.78);
  neuron.set(Neuron::vs_h, -8.41);
  neuron.set(Neuron::vs_n, 34.79);
  neuron.set(Neuron::vs_r, 20.55);

  neuron.set(Neuron::v, v0);
  neuron.set(Neuron::h, 1 / (1 + exp( (neuron.get(Neuron::vh_h) - v0) / neuron.get(Neuron::vs_h))));
  neuron.set(Neuron::r, 1 / (1 + exp( (neuron.get(Neuron::vh_r) - v0) / neuron.get(Neuron::vs_r))));
  neuron.set(Neuron::a, 1 / (1 + exp( (neuron.get(Neuron::vh_a) - v0) / neuron.get(Neuron::vs_a))));
  neuron.set(Neuron::b, 1 / (1 + exp( (neuron.get(Neuron::vh_b) - v0) / neuron.get(Neuron::vs_b))));
  neuron.set(Neuron::n, 1 / (1 + exp( (neuron.get(Neuron::vh_n) - v0) / neuron.get(Neuron::vs_n))));
  neuron.set(Neuron::e, 1 / (1 + exp( (neuron.get(Neuron::vh_e) - v0) / neuron.get(Neuron::vs_e))));
  neuron.set(Neuron::f, 1 / (1 + exp( (neuron.get(Neuron::vh_f) - v0) / neuron.get(Neuron::vs_f))));  
}

void
NeunCgcForRtxi::update(DefaultGUIModel::update_flags_t flag)
{
  switch (flag) {
    case INIT:
      period = RT::System::getInstance()->getPeriod() * 1e-6; // ms
      
      setParameter("Iext", i_ext);
      setParameter("step", step);

      param_names = Neuron::ParamNames();
      for (int i = 0; i < Neuron::n_parameters; i++) {
    // Convert std::string to QString for setParameter
        QString paramName = QString::fromStdString(param_names[i]);
        double paramValue = static_cast<double>(
            neuron.get(static_cast<VavoulisCGCModelQ10<double>::parameter>(i))
        );
        setParameter(paramName, paramValue);
      }
      param_names_qt.clear();
      param_names_qt.push_back(QString::fromStdString("Iext"));
      param_names_qt.push_back(QString::fromStdString("step"));
      for (const auto& name : Neuron::ParamNames()) {
          param_names_qt.push_back(QString::fromStdString(name));
      }

      break;

    case MODIFY:
      i_ext = getParameter(param_names_qt[0]).toDouble();
      step = getParameter(param_names_qt[1]).toDouble();
      printf("Setting %s\n",param_names_qt[0].toStdString().c_str());
      printf("Setting %s\n",param_names_qt[1].toStdString().c_str());
      for (int i = 0; i < Neuron::n_parameters; i++) {
        printf("Setting %s\n",param_names_qt[i+2].toStdString().c_str());
        double value = getParameter(param_names_qt[i+2]).toDouble();
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
  QPushButton* bbutton = new QPushButton("Print Parameters");
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
void NeunCgcForRtxi::printParameters() { 
  std::vector<std::string> param_names = Neuron::ParamNames();

  for(int i=0; i < Neuron::n_parameters; i++)
  {
    printf("%s %f\n",param_names[i].c_str(),
          neuron.get(static_cast<VavoulisCGCModelQ10<double>::parameter>(i)));
  }
}

void
NeunCgcForRtxi::bBttn_event(void)
{
  printParameters();
  printf("Iext %f\n",i_ext);
  printf("step %f\n",step);
  printf("Input %f\n",input(0));
}

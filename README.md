# NeunCgcForRtxi

**NeunCgcForRtxi** is a real-time neuron model module for [RTXI](https://rtxi.org/), based on a **Q10 temperature-sensitive conductance-based model** of a central ganglion cell (CGC). It uses the [Neun](https://github.com/Neun) neuron simulation library for defining and simulating intrinsic ionic conductances.

---

## Features

- Real-time CGC neuron simulation with biologically realistic currents.
- Q10-based temperature scaling of conductances.
- GUI-based interaction for all key model parameters.
- Control buttons for resetting and printing parameters.
- Integration with RTXI for real-time experiments.

---

## Requirements

- [RTXI](https://rtxi.org/)
- Qt5 (for GUI widgets)
- [Neun library](https://github.com/GNB-UAM/Neun)

---

## Neun Dependency

This module depends on the [Neun library](https://github.com/GNB-UAM/Neun). Clone and build it before compiling this module

Ensure the Neun headers and libraries are accessible when compiling.

---

## Build Instructions

### Option 1: Manual Compile

```bash
g++ -std=c++11 -fPIC \
    -I/path/to/Neun/include \
    -I$RTXI_INCLUDE -I$QT_INCLUDE \
    -L/path/to/Neun/lib -lneun \
    -shared -o neun_cgc_for_rtxi.so neun_cgc_for_rtxi.cpp
```

Replace `/path/to/Neun`, `$RTXI_INCLUDE`, and `$QT_INCLUDE` with appropriate paths.

---

## Using in RTXI

1. Launch RTXI.
2. Load `neun_cgc_for_rtxi.so` through RTXI’s module loader.
3. The GUI lets you adjust:
   - Temperature (°C)
   - External current (`I_ext`)
   - Maximal conductances (e.g. `gna`, `gnaP`, `gK`, `gh`)
   - Q10 parameters
   - Initial conditions
   - Activation variables in channels

4. Use the GUI buttons:
   - **Reset initial**: Reinitialize state variables and parameters.
   - **Print Parameters**: Dump current parameter set to console.

5. Outputs include:
   - Membrane voltage
   - Ionic currents (`Ia`, `Id`, `Ihva`, `Ilva`, `Inap`, `Inat`)
   - Synaptic input current

---

## Notes

- Parameter saving/loading from YAML is stubbed (currently inactive).
- Model equations and gating are implemented via Neun's `ConductanceBasedNeuron`.
- Initial gating values are calculated via Boltzmann functions.

---

## 📄 License

MIT License. For full model framework and licensing, see the [Neun GitHub repository](https://github.com/Neun).

---

## 🙏 Acknowledgments

- [RTXI: Real-Time eXperiment Interface](https://rtxi.org/)
- [Neun: Neuron Modeling Framework](https://github.com/Neun)

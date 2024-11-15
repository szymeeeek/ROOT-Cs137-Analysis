# ROOT Macros for Cs-137 Spectrum Analysis

This repository contains several ROOT macros for analyzing the Cs-137 gamma spectrum, formatting histograms, and working with data in both text and binary formats. Below is a detailed description of each macro and its purpose.

---

## Macro 1: `WidmoCs.C`
**Description**:  
This macro reads a text file containing Cs-137 spectrum data, processes it into a ROOT histogram, and visualizes the result.

**Functionality**:
- Reads the data from a text file (default: `Cs-137.dat`).
- Verifies if the file is opened successfully and prints appropriate messages.
- Displays the data on the console for verification.
- Creates a histogram from the data and assigns appropriate measurement uncertainties to each bin.
- Formats the histogram by setting axis ranges, adding axis labels with units, and highlighting key features like the photopeak and Compton edge.
- Saves the histogram and canvas into a ROOT file for later use.

**Key Commands**:
- **Usage**: `WidmoCs("filename.dat");`
- Default file: `Cs-137.dat`.

---

## Macro 2: `RewriteFile.C`
**Description**:  
Converts the Cs-137 spectrum data from a text format to a binary format for efficient storage and processing.

**Functionality**:
- Reads the contents of `Cs-137.dat`.
- Converts and writes the data into a binary file named `Cs-137.bin`.
- Provides a way to verify the contents of the resulting binary file.

**Key Commands**:
- **Usage**: `RewriteFile();`
- Output file: `Cs-137.bin`.

---

## Macro 3: `WidmoCsBin.C`
**Description**:  
A modified version of `WidmoCs.C` that reads Cs-137 data from a binary file instead of a text file.

**Functionality**:
- Reads the binary data from `Cs-137.bin`.
- Processes the data into a histogram, similar to `WidmoCs.C`.
- Includes all functionalities of `WidmoCs.C`, such as formatting the histogram, highlighting key features, and saving the results.

**Key Commands**:
- **Usage**: `WidmoCsBin("filename.bin");`
- Default file: `Cs-137.bin`.

---

## Macro 4: `HistogramStack.C`
**Description**:  
Generates and visualizes a stack of histograms that look like a Minecraft world topology using different random distributions.

**Functionality**:
- Creates four histograms filled with data from different pseudorandom number distributions (e.g., Gaussian, exponential, Landau, polynomial).
- Combines the histograms into a `THStack` to display them together on the same pad.
- Adds a legend to identify each distribution.
- Formats the image for better readability.

**Key Commands**:
- **Usage**: `HistogramStack();`

---

## Setup Instructions
1. **Prerequisites**: Ensure ROOT is installed and properly configured.
2. **Compilation and Execution**:
   - Run the macros interactively in the ROOT prompt:
     ```bash
     root -l
     .L MacroName.C
     MacroName();
     ```
   - Alternatively, compile and execute them using:
     ```bash
     root MacroName.C
     ```

---

## Checklist
- `WidmoCs.C`: Text-based data processing.
- `RewriteFile.C`: Text-to-binary conversion.
- `WidmoCsBin.C`: Binary data processing.
- `HistogramStack.C`: Visualization of stacked histograms.

Feel free to experiment with the macros and adapt them to other datasets. Feedback is welcome to ensure proper functionality and readability!

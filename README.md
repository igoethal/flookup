# flookup
A set of DLL library functions to bring the Levenshtein distance metric and a fuzzy lookup to Excel

Build the code in visual studio as Release to either x86 or x64

Copy the generated DLL (usually stored in a folder "Release") to a desired location, e.g. "c:\users\ <username>\lib\flookup".

Open one of the example Excel files, go into the visual basic editor and change the 4 Declare statements to point to your chosen location.
Note that a 32 bit Excel installation can only access 32 bit DLL's and the same is true to 64 bit Excel. Mixing is not possible.

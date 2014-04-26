stb_image
=========

Mono/.Net port of [stb_image](http://nothings.org/).

This is a C++/CLI project, compiled with /clr:pure and /NODEFAULTLIB, which removes all unmanaged code from the resulting assembly. It should, in principle, run on Mono. Replacements have been implemented for malloc, memset and all other CRT methods used by stb_image. See http://mono-project.com/CPlusPlus for more information.

We still need:
1. a public, CLS-compliant API that can be used from C#
2. to move all static initializers to the .cctor method

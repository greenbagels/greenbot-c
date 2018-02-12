# greenbot-c

Rewrite of my earlier C++ bot, but from scratch this time.

Designed for speed, portability, and *as much* safety as we can get.

# Design

greenbot-c is intended to maximize responsiveness while maintaining robustness.
In less abstract buzzwordy terms, this means the following features are planned:
- hot-swappable modules (via `.so` files and `dlsym`)
- multithreading
- platform agnosticism (cmake, anyone?)

Potential experimental additions in the future may include
- GPU acceleration ;)
- third-party script / language support

# Contributing / Code of Conduct
greenbot-c is a great opportunity to sharpen your C skills (and mine, too!).
If you have a suggestion, feel free to make an issue or email me. Help is
always appreciated. Just one rule for now --- be civil in discussion.

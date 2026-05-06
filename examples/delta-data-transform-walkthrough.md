# Delta Data Transform Pipe Walkthrough

I use this file as a small checklist before changing the C++ implementation.

| Case | Focus | Score | Lane |
| --- | --- | ---: | --- |
| baseline | schema drift | 111 | watch |
| stress | lineage depth | 201 | ship |
| edge | partition skew | 216 | ship |
| recovery | quality gap | 250 | ship |
| stale | schema drift | 224 | ship |

Start with `recovery` and `baseline`. They create the widest contrast in this repository's fixture set, which makes them better review anchors than the middle cases.

The next useful expansion would be a malformed fixture around lineage depth and quality gap.

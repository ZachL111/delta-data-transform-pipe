# Field Notes

The useful part of this repository is the small rule set around schema drift and partition skew.

The domain cases cover `schema drift`, `lineage depth`, `partition skew`, and `quality gap`. They sit beside the smaller starter fixture so the project has both a compact scoring check and a domain-flavored review check.

The widest spread is between `quality gap` and `schema drift`, so those are the first two cases I would preserve during a refactor.

The language-specific addition keeps the review model behind a small header and compiled test harness.

# Review Journal

The review surface for `delta-data-transform-pipe` is deliberately narrow: one fixture, one scoring rule, and one local check.

The local checks classify each case as `ship`, `watch`, or `hold`. That gives the project a small review vocabulary that matches its data engineering focus without claiming live deployment or external usage.

## Cases

- `baseline`: `schema drift`, score 111, lane `watch`
- `stress`: `lineage depth`, score 201, lane `ship`
- `edge`: `partition skew`, score 216, lane `ship`
- `recovery`: `quality gap`, score 250, lane `ship`
- `stale`: `schema drift`, score 224, lane `ship`

## Note

The useful failure mode here is a wrong decision on a named case, not a vague style disagreement.

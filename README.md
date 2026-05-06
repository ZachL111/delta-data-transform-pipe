# delta-data-transform-pipe

`delta-data-transform-pipe` is a C++ project in data engineering. Its focus is to build a C++ toolkit that studies transform behavior through node-edge fixtures, with cycle and reachability reports and synthetic fixtures only.

## Problem It Tries To Make Smaller

The project exists to keep a narrow engineering decision visible and testable. For this repo, that decision is how schema drift and partition skew should influence a review result.

## Delta Data Transform Pipe Review Notes

The first comparison I would make is `quality gap` against `schema drift` because it shows where the rule is most opinionated.

## Working Pieces

- `fixtures/domain_review.csv` adds cases for schema drift and lineage depth.
- `metadata/domain-review.json` records the same cases in structured form.
- `config/review-profile.json` captures the read order and the two review questions.
- `examples/delta-data-transform-walkthrough.md` walks through the case spread.
- The C++ code includes a review path for `quality gap` and `schema drift`.
- `docs/field-notes.md` explains the strongest and weakest cases.

## Design Notes

The repository has two validation layers: the original compact policy fixture and the domain review fixture. They are separate so one can change without hiding failures in the other.

The C++ code keeps the review rule close to the tests.

## Example Run

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/verify.ps1
```

## Tests

The same command runs the local verification path. The highest-scoring domain case is `recovery` at 250, which lands in `ship`. The most cautious case is `baseline` at 111, which lands in `watch`.

## Known Limits

The repository is intentionally scoped to local checks. I would expand it by adding adversarial fixtures before adding features.

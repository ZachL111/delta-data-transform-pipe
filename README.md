# delta-data-transform-pipe

`delta-data-transform-pipe` packages a practical data engineering exercise in C++. The emphasis is on deterministic behavior, a small public API, and examples that explain the tradeoffs.

## How I Read Delta Data Transform Pipe

The useful thing to inspect here is how the same score rule is represented in code, metadata, and examples. If those three pieces disagree, the audit script should make the drift visible.

## Problem Shape

The goal is to capture the core behavior in code and make the surrounding assumptions obvious. A reader should be able to run the verifier, open the fixtures, and understand why each decision was made.

## Repository Map

- `src`: primary implementation
- `tests`: verification harness
- `fixtures`: compact golden scenarios
- `examples`: expanded scenario set
- `metadata`: project constants and verification metadata
- `docs`: operations and extension notes
- `scripts`: local verification and audit commands

## Main Behaviors

- Includes extended examples for pipeline state, including `surge` and `degraded`.
- Documents quality gates tradeoffs in `docs/operations.md`.
- Runs locally with a single verification command and no external credentials.
- Stores project constants and verification metadata in `metadata/project.json`.
- Adds a repository audit script that checks structure before running the language verifier.

## Internal Model

The core is a scoring model over demand, capacity, latency, risk, and weight. That keeps schema drift, lineage checks, and pipeline state in one explicit decision path. The threshold is 168, with risk penalty 6, latency penalty 2, and weight bonus 5. The C++ project uses a small library boundary and a compiled assertion harness.

## Run It Locally

Install C++ and run the commands from the repository root. The project does not need credentials or a hosted service.

## Scenario Walkthrough

The examples are meant to be readable before they are exhaustive. They cover enough variation to show how latency and risk can pull a decision below the threshold.

## How To Run It

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/verify.ps1
```

This runs the language-level build or test path against the compact fixture set.

## Validation

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/audit.ps1
```

The audit command checks repository structure and README constraints before it delegates to the verifier.

## Follow-Up Work

- Add malformed input fixtures so the failure path is as visible as the happy path.
- Split the scoring constants into a typed configuration object and validate it before use.
- Add a comparison mode that shows how decisions change when one signal is adjusted.
- Add one more data engineering fixture that focuses on a malformed or borderline input.

## Known Edges

The fixture set is deliberately small. That keeps the review surface clear, but it also means the model should not be treated as a complete domain simulator.

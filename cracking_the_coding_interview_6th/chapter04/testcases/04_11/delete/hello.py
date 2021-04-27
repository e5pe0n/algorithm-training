from pathlib import Path

delete_dir = (Path(__file__) / "..").resolve()
for f in sorted(list(delete_dir.glob("*.txt"))):
    n = int(f.stem)
    f.rename(delete_dir / f"{n - 1:02d}.txt")

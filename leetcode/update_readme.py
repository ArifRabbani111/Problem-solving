import os

readme_header = """# LeetCode Progress
| # | Problem | Solution | Difficulty |
|---|---------|----------|------------|
"""

solutions = []
for filename in os.listdir("solutions"):
    if filename.endswith((".cpp", ".py", ".java")):
        parts = filename.split("-")
        problem_id = parts[0]
        problem_name = " ".join(parts[1:]).replace(".cpp", "").replace(".py", "").title()
        solutions.append((problem_id, problem_name, filename))

solutions.sort(key=lambda x: int(x[0]))

with open("README.md", "w") as f:
    f.write(readme_header)
    for id, name, file in solutions:
        f.write(f"| {id} | [{name}](https://leetcode.com/problems/{name.lower().replace(' ', '-')}/) | [{file}](solutions/{file}) | Medium |\n")
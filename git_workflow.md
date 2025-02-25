# Git Workflow & Branch Naming Convention
A well-structured Git workflow ensures that all contributors follow a consistent process, reducing merge conflicts and keeping the repository clean.

---

### **Main Branches**
These branches are permanent and should always be kept in a stable state.

`main`:  Stable production-ready build. Only final, tested versions of the game are merged here. 
`develop`: The latest working version where new features are integrated and tested before a stable release.


### **Supporting Branches**

`feature/xxx` : Developing new game features
`fix/xxx`  : Fixing bugs or issues
`hotfix/xxx` : Critical fixes for `main` that need immediate release 
`release/xxx` : Preparing a stable version for release


## Git Workflow Steps

###  **1. Setting Up the Repo**
- Clone the repository:
  ```
  git clone <repo-url>
  cd <repo-name>
  ```

- Set up tracking for `main` and `develop`:
  ```
  git checkout main
  git pull origin main
  git checkout develop
  git pull origin develop
  ```

### **2. Creating a New Feature**
- Always create a new branch from `develop` for new features:
  ```
  git checkout develop
  git pull origin develop
  git checkout -b feature/render-pipeline
  ```
- Work on the feature, commit changes:
  ```
  git add .
  git commit -m "[FEATURE] Implemented render pipeline selection"
  ```
- Push the branch to remote:
  ```
  git push origin feature/render-pipeline
  ```


### **3. Creating a Pull Request (PR)**
- Once the feature is ready, create a **Pull Request (PR)** from `feature/render-pipeline` to `develop`.
- Get it reviewed and approved.
- Merge it into `develop`.

### **4. Testing & Merging to Main**
- Once all features for a release are merged into `develop`, test the branch.
- When stable, merge `develop` into `main`:
  ```
  git checkout main
  git merge develop
  git push origin main
  ```

---

## Example Branch Naming

| Branch Type | Naming Convention | Example |
|-------------|------------------|---------|
| Feature | `feature/feature-name` | `feature/inventory-system` |
| Bug Fix | `fix/issue-name` | `fix/camera-clipping` |
| Hotfix | `hotfix/critical-fix` | `hotfix/game-crash` |
| Experiment | `experiment/idea-name` | `experiment/ai-npc` |
| Release | `release/version` | `release/v1.0.0` |

---

## Best Practices
- Always **branch off** from `develop`, **never from `main`**.
- Use **descriptive commit messages** (e.g., `[FEATURE] Added physics-based water simulation`).
- Keep feature branches **short-lived** and merge them quickly.
- **Delete feature branches** once they are merged into `develop`.
- Use **PR reviews** before merging to `develop` or `main`.

---

## Commit Message Format
To maintain a consistent and clear commit history, follow this commit message format:

```
[TAG] Short summary of changes
```

---

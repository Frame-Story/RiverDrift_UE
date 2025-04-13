
# "fast forward"
used for when one person has made changes that have been rebased onto another branch, and wants someone else (you) to bring your branch up to date with those changes

## process
open sourcetree, click the "terminal icon in the top right of the screen 
![[Pasted image 20250413123518.png]]
this will open a new command line window
![[Pasted image 20250413123536.png]]

type in the following command:

```bash
git merge origin/branch/name --ff-only
```

in which origin/branch/name is the name of the branch who's changes you are trying to bring up to date with your own. Usually Ryan will provide this for you. if you don't know what it should be then ask

this will fast forward the branch you are on to be up todate with your own IF AND ONLY IF the two share a linear commit history. if the two don't share a linear history, then the command will fail. If you get a failure then likely something went wrong with either you calling the command, or with ryan rebasing the changes. 
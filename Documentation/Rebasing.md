# overview
Rebasing is a special method of merging branches that rewrites the history of two separate branches so that one originated from the other.

I recommend reading the following page, as it will provide further and more accurate details, but I'll also provide a brief summary below:
https://www.atlassian.com/git/tutorials/rewriting-history/git-rebase

![[01 What is git rebase.svg]]
## definitions:

based on the following diagram, we are "Rebasing branch A onto branch B"

A         		   A---B---C                          # subject
		/
B     	     D---E---F---G                         # target	<br>	
into	 <br>
A  				                A'--B'--C'          # subject
				 /
B          D---E---F---G                           # target



"target branch" the branch you are trying to rebase onto. 
	In the diagram above, the target branch is B. 
	the final history will include the target branch before the feature branch
"subject branch" - the branch you are trying to rebase. 
	in the diagram above, the subject branch is A



# in practice
most common method will be to bring your changes up to date with the changes that others have shared ("bringing up to date with main")

## Definitions

in this case, you are rebasing your feature branch (e.g. "feature/sprites/justin" onto main)
that is to say, your feature branch is your **subject** and **main** is your target

note, for the rest of this example, I'll be referring primarily to "feature/sprites"

the steps:
checkout your current branch, right click the commit/branch that has the changes you want to bring up to date
![[Pasted image 20250411144218.png]]
the current checked out branch is "Documentation" (indicated by the bold text). In the time since Documentation was created, Justin pushed changes to feature/sprites/justin. I then added a small set of changes to that same branch. 
for the sake of this documentation, I've avoided making any changes

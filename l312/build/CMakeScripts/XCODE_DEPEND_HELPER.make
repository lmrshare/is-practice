# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.l312.Debug:
/Users/linmengran-mac2/work/2.code_practice/is-practice/leetcode_projs/l312/build/Debug/l312:
	/bin/rm -f /Users/linmengran-mac2/work/2.code_practice/is-practice/leetcode_projs/l312/build/Debug/l312


PostBuild.l312.Release:
/Users/linmengran-mac2/work/2.code_practice/is-practice/leetcode_projs/l312/build/Release/l312:
	/bin/rm -f /Users/linmengran-mac2/work/2.code_practice/is-practice/leetcode_projs/l312/build/Release/l312


PostBuild.l312.MinSizeRel:
/Users/linmengran-mac2/work/2.code_practice/is-practice/leetcode_projs/l312/build/MinSizeRel/l312:
	/bin/rm -f /Users/linmengran-mac2/work/2.code_practice/is-practice/leetcode_projs/l312/build/MinSizeRel/l312


PostBuild.l312.RelWithDebInfo:
/Users/linmengran-mac2/work/2.code_practice/is-practice/leetcode_projs/l312/build/RelWithDebInfo/l312:
	/bin/rm -f /Users/linmengran-mac2/work/2.code_practice/is-practice/leetcode_projs/l312/build/RelWithDebInfo/l312




# For each target create a dummy ruleso the target does not have to exist

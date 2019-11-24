# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.l109.Debug:
/Users/linmengran-mac2/work/2.code_practice/is-practice/l109/build/Debug/l109:
	/bin/rm -f /Users/linmengran-mac2/work/2.code_practice/is-practice/l109/build/Debug/l109


PostBuild.l109.Release:
/Users/linmengran-mac2/work/2.code_practice/is-practice/l109/build/Release/l109:
	/bin/rm -f /Users/linmengran-mac2/work/2.code_practice/is-practice/l109/build/Release/l109


PostBuild.l109.MinSizeRel:
/Users/linmengran-mac2/work/2.code_practice/is-practice/l109/build/MinSizeRel/l109:
	/bin/rm -f /Users/linmengran-mac2/work/2.code_practice/is-practice/l109/build/MinSizeRel/l109


PostBuild.l109.RelWithDebInfo:
/Users/linmengran-mac2/work/2.code_practice/is-practice/l109/build/RelWithDebInfo/l109:
	/bin/rm -f /Users/linmengran-mac2/work/2.code_practice/is-practice/l109/build/RelWithDebInfo/l109




# For each target create a dummy ruleso the target does not have to exist

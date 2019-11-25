# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.ch2.Debug:
/Users/linmengran-mac2/work/2.code_practice/is-practice/ch2/build-mac/Debug/ch2:
	/bin/rm -f /Users/linmengran-mac2/work/2.code_practice/is-practice/ch2/build-mac/Debug/ch2


PostBuild.ch2.Release:
/Users/linmengran-mac2/work/2.code_practice/is-practice/ch2/build-mac/Release/ch2:
	/bin/rm -f /Users/linmengran-mac2/work/2.code_practice/is-practice/ch2/build-mac/Release/ch2


PostBuild.ch2.MinSizeRel:
/Users/linmengran-mac2/work/2.code_practice/is-practice/ch2/build-mac/MinSizeRel/ch2:
	/bin/rm -f /Users/linmengran-mac2/work/2.code_practice/is-practice/ch2/build-mac/MinSizeRel/ch2


PostBuild.ch2.RelWithDebInfo:
/Users/linmengran-mac2/work/2.code_practice/is-practice/ch2/build-mac/RelWithDebInfo/ch2:
	/bin/rm -f /Users/linmengran-mac2/work/2.code_practice/is-practice/ch2/build-mac/RelWithDebInfo/ch2




# For each target create a dummy ruleso the target does not have to exist

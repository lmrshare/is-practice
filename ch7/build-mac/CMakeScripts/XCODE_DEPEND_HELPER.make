# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.ch7.Debug:
/Users/linmengran-mac2/work/code_practice/is-practice/ch7/build-mac/Debug/ch7:
	/bin/rm -f /Users/linmengran-mac2/work/code_practice/is-practice/ch7/build-mac/Debug/ch7


PostBuild.ch7.Release:
/Users/linmengran-mac2/work/code_practice/is-practice/ch7/build-mac/Release/ch7:
	/bin/rm -f /Users/linmengran-mac2/work/code_practice/is-practice/ch7/build-mac/Release/ch7


PostBuild.ch7.MinSizeRel:
/Users/linmengran-mac2/work/code_practice/is-practice/ch7/build-mac/MinSizeRel/ch7:
	/bin/rm -f /Users/linmengran-mac2/work/code_practice/is-practice/ch7/build-mac/MinSizeRel/ch7


PostBuild.ch7.RelWithDebInfo:
/Users/linmengran-mac2/work/code_practice/is-practice/ch7/build-mac/RelWithDebInfo/ch7:
	/bin/rm -f /Users/linmengran-mac2/work/code_practice/is-practice/ch7/build-mac/RelWithDebInfo/ch7




# For each target create a dummy ruleso the target does not have to exist

# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.ch6.Debug:
/Users/linmengran-mac2/work/code_practice/is-practice/ch6/build-mac/Debug/ch6:
	/bin/rm -f /Users/linmengran-mac2/work/code_practice/is-practice/ch6/build-mac/Debug/ch6


PostBuild.ch6.Release:
/Users/linmengran-mac2/work/code_practice/is-practice/ch6/build-mac/Release/ch6:
	/bin/rm -f /Users/linmengran-mac2/work/code_practice/is-practice/ch6/build-mac/Release/ch6


PostBuild.ch6.MinSizeRel:
/Users/linmengran-mac2/work/code_practice/is-practice/ch6/build-mac/MinSizeRel/ch6:
	/bin/rm -f /Users/linmengran-mac2/work/code_practice/is-practice/ch6/build-mac/MinSizeRel/ch6


PostBuild.ch6.RelWithDebInfo:
/Users/linmengran-mac2/work/code_practice/is-practice/ch6/build-mac/RelWithDebInfo/ch6:
	/bin/rm -f /Users/linmengran-mac2/work/code_practice/is-practice/ch6/build-mac/RelWithDebInfo/ch6




# For each target create a dummy ruleso the target does not have to exist

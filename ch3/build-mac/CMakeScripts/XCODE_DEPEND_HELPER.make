# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.ch3.Debug:
/Volumes/LMR_1T/base/ee/information-science-code/is-practice/ch3/build-mac/Debug/ch3:
	/bin/rm -f /Volumes/LMR_1T/base/ee/information-science-code/is-practice/ch3/build-mac/Debug/ch3


PostBuild.ch3.Release:
/Volumes/LMR_1T/base/ee/information-science-code/is-practice/ch3/build-mac/Release/ch3:
	/bin/rm -f /Volumes/LMR_1T/base/ee/information-science-code/is-practice/ch3/build-mac/Release/ch3


PostBuild.ch3.MinSizeRel:
/Volumes/LMR_1T/base/ee/information-science-code/is-practice/ch3/build-mac/MinSizeRel/ch3:
	/bin/rm -f /Volumes/LMR_1T/base/ee/information-science-code/is-practice/ch3/build-mac/MinSizeRel/ch3


PostBuild.ch3.RelWithDebInfo:
/Volumes/LMR_1T/base/ee/information-science-code/is-practice/ch3/build-mac/RelWithDebInfo/ch3:
	/bin/rm -f /Volumes/LMR_1T/base/ee/information-science-code/is-practice/ch3/build-mac/RelWithDebInfo/ch3




# For each target create a dummy ruleso the target does not have to exist

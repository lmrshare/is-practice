# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.ch4.Debug:
/Volumes/LMR_1T/base/ee/information-science-code/is-practice/ch4/build-mac/Debug/ch4:
	/bin/rm -f /Volumes/LMR_1T/base/ee/information-science-code/is-practice/ch4/build-mac/Debug/ch4


PostBuild.ch4.Release:
/Volumes/LMR_1T/base/ee/information-science-code/is-practice/ch4/build-mac/Release/ch4:
	/bin/rm -f /Volumes/LMR_1T/base/ee/information-science-code/is-practice/ch4/build-mac/Release/ch4


PostBuild.ch4.MinSizeRel:
/Volumes/LMR_1T/base/ee/information-science-code/is-practice/ch4/build-mac/MinSizeRel/ch4:
	/bin/rm -f /Volumes/LMR_1T/base/ee/information-science-code/is-practice/ch4/build-mac/MinSizeRel/ch4


PostBuild.ch4.RelWithDebInfo:
/Volumes/LMR_1T/base/ee/information-science-code/is-practice/ch4/build-mac/RelWithDebInfo/ch4:
	/bin/rm -f /Volumes/LMR_1T/base/ee/information-science-code/is-practice/ch4/build-mac/RelWithDebInfo/ch4




# For each target create a dummy ruleso the target does not have to exist

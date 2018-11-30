module: ElectronTouchID.framework

ElectronTouchID.framework:
	rm -rf out
	mkdir out
	xcodebuild -project ElectronTouchID.xcodeproj -target ElectronTouchID -configuration Release -sdk macosx CONFIGURATION_BUILD_DIR=out clean build

clean:
	rm -rf out

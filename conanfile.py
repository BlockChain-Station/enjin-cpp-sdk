from conans import ConanFile, CMake, tools


class EnjinCPPSDK(ConanFile):
    name = "enjincppsdk"
    version = "1.0.0-alpha.2"
    description = "A C++ SDK for development on the Enjin blockchain platform."
    homepage = "https://enjin.io/"
    url = "https://github.com/enjin/enjin-cpp-sdk"
    license = "Apache-2.0"
    author = "Enjin Pte. Ltd."
    topics = ("conan", "enjin", "sdk", "blockchain", "cpp")
    settings = "os", "compiler", "arch", "build_type"
    generators = "cmake"
    options = {
        "enable_default_http_client": [True, False],
        "enable_default_ws_client": [True, False],
    }
    default_options = {
        "enable_default_http_client": False,
        "enable_default_ws_client": False,
    }

    def build(self):  # Building just the tests
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        if tools.get_env("CONAN_RUN_TESTS", True):
            cmake.test()

    def imports(self):
        self.copy("*.lib", "", "bin")

    def package(self):
        self.copy("*.h", dst="include", src="include/enjinsdk")
        self.copy("*enjinsdk.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.dylib", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def requirements(self):
        if self.options.enable_default_http_client:
            self.requires("cpp-httplib/0.8.5")
            self.requires("openssl/1.1.1m")
        if self.options.enable_default_ws_client:
            self.requires("ixwebsocket/11.0.4")

        self.requires("gtest/1.10.0")
        self.requires("rapidjson/1.1.0")
        self.requires("spdlog/1.8.2")

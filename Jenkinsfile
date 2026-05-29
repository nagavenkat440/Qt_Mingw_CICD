pipeline {
agent any


environment {
    PATH = "C:\\Qt\\Qt5.12.12\\Tools\\mingw730_64\\bin;C:\\Qt\\Qt5.12.12\\5.12.12\\mingw73_64\\bin;${env.PATH}"
}

stages {

    stage('Checkout') {
        steps {
            git branch: 'main',
                url: 'https://github.com/nagavenkat440/Qt_Mingw_CICD.git'
        }
    }

    stage('Clean') {
        steps {
            bat 'if exist build rmdir /S /Q build'
        }
    }

    stage('Configure') {
        steps {
            bat '''
            cmake -S . -B build ^
            -G "MinGW Makefiles" ^
            -DCMAKE_C_COMPILER=C:/Qt/Qt5.12.12/Tools/mingw730_64/bin/gcc.exe ^
            -DCMAKE_CXX_COMPILER=C:/Qt/Qt5.12.12/Tools/mingw730_64/bin/g++.exe ^
            -DCMAKE_PREFIX_PATH=C:/Qt/Qt5.12.12/5.12.12/mingw73_64
            '''
        }
    }

    stage('Build') {
        steps {
            bat 'cmake --build build'
        }
    }

    stage('Test') {
        steps {
            bat '''
            build\\runTests.exe --gtest_output=xml:test_results.xml
            '''
        }
    }

    stage('Archive Artifacts') {
        steps {
            archiveArtifacts artifacts: 'build/**/*', fingerprint: true
        }
    }
}

post {
    always {
        junit 'test_results.xml'
        echo 'Pipeline Finished'
    }

    success {
        echo 'Build and Tests Passed'
    }

    failure {
        echo 'Build or Tests Failed'
    }
}


}

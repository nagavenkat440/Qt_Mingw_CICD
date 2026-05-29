pipeline {

agent any

stages {

    stage('Checkout') {
        steps {
            git branch: 'main',
                url: 'https://github.com/nagavenkat440/Qt_Mingw_CICD.git'
        }
    }

    stage('Clean') {
        steps {
            bat '''
            if exist build (
                rmdir /S /Q build
            )
            '''
        }
    }

    stage('Configure') {
        steps {
            bat 'cmake -S . -B build'
        }
    }

    stage('Build') {
        steps {
            bat 'cmake --build build'
        }
    }

    stage('Test') {
        steps {
            bat 'ctest --test-dir build --output-on-failure'
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

pipeline {
    agent any
    stages {
        stage('Prepare') { 
            steps {
                sh 'apt update'
                sh 'apt install make -y'
            }
        }
        stage('Build') { 
            steps {
                sh 'make clean'
                sh 'make'
            }
        }
    }
}

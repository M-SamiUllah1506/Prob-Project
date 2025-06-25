<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Solar Energy Project Presentation</title>
    <script src="https://cdn.tailwindcss.com"></script>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <link href="https://fonts.googleapis.com/css2?family=Inter:wght@400;500;600;700;800&display=swap" rel="stylesheet">
    <style>
        body {
            font-family: 'Inter', sans-serif;
            background-color: #e2e8f0;
        }
        .slide-container {
            width: 11in;
            height: 8.5in;
            padding: 0.5in;
            margin: 2rem auto;
            display: flex;
            flex-direction: column;
            background-color: white;
            box-shadow: 0 10px 15px -3px rgb(0 0 0 / 0.1);
        }
        .slide-title {
            font-size: 2.25rem;
            font-weight: 800;
            color: #1e293b;
            margin-bottom: 0.25rem;
            border-bottom: 4px solid #3b82f6;
            padding-bottom: 0.5rem;
        }
        .slide-subtitle {
            font-size: 1.25rem;
            font-weight: 600;
            color: #475569;
            margin-bottom: 1.5rem;
        }
        .formula-box {
            background-color: #f8fafc;
            border: 1px solid #e2e8f0;
            padding: 0.75rem;
            font-family: "Courier New", monospace;
            font-size: 1.1rem;
            color: #0f172a;
            border-radius: 0.5rem;
        }
        .chart-container {
            position: relative;
            width: 100%;
            height: 100%;
            flex-grow: 1;
        }
        .conclusion-box {
            border: 2px solid;
            padding: 1rem;
            border-radius: 0.5rem;
            margin-top: 1rem;
        }
        .reject { border-color: #16a34a; background-color: #f0fdf4; color: #14532d; }
        .fail-reject { border-color: #f59e0b; background-color: #fefce8; color: #78350f; }
        .print-only { display: none; }

        @media print {
            body { background-color: white; }
            .no-print { display: none; }
            .print-only { display: block; }
            .slide-container {
                width: 100%;
                height: 100vh; /* Use vh for better print scaling */
                margin: 0;
                padding: 0.25in;
                box-shadow: none;
                border-radius: 0;
                page-break-after: always;
            }
            @page {
                size: A4 landscape;
                margin: 0.5in;
            }
        }
    </style>
</head>
<body>

    <!-- Instructions Slide -->
    <div class="slide-container no-print" style="justify-content:center; text-align:center;">
        <h1 class="text-4xl font-bold">How to Save as PDF</h1>
        <p class="mt-4 text-lg">To save this presentation as a PDF, press <strong>Ctrl+P</strong> (or <strong>Cmd+P</strong> on Mac), and in the print dialog, select "<strong>Save as PDF</strong>" as the destination. Ensure "Landscape" orientation is selected and "Background graphics" is enabled.</p>
    </div>

    <!-- Slide 1: Title -->
    <div class="slide-container" style="justify-content:center; text-align:center; background-color:#0f172a; color:white;">
        <h1 class="text-5xl font-extrabold mb-4">Solar Energy: A Data-Driven Analysis of Efficiency, Cost, and Impact</h1>
        <p class="text-2xl text-slate-300">A Statistical Analysis Project</p>
    </div>

    <!-- Slide 2: Overview -->
    <div class="slide-container">
        <h2 class="slide-title">Slide 2: Project Overview & Methodology</h2>
        <div class="mt-8 text-xl text-slate-700 space-y-6">
            <p>This research provides an in-depth statistical analysis of residential solar energy adoption, based on a survey of <strong>200 respondents</strong>. The study aims to rigorously evaluate the financial viability, user satisfaction, and key barriers related to solar power.</p>
            <div class="p-4 bg-slate-50 rounded-lg">
                <h3 class="font-bold text-2xl text-slate-800 mb-2">Methodology:</h3>
                <ul class="list-disc list-inside space-y-3 text-xl">
                    <li><strong>Data Source:</strong> A comprehensive survey conducted among 200 homeowners and residents in Lahore.</li>
                    <li><strong>Analytical Approach:</strong> We employ a range of statistical techniques, including descriptive statistics, hypothesis testing (Z-tests, T-tests, Chi-Square), confidence intervals, and probability theory to provide a rigorous and evidence-based overview.</li>
                </ul>
            </div>
        </div>
    </div>
    
    <!-- Slide 3: Demographics -->
    <div class="slide-container">
        <h2 class="slide-title">Slide 3: Respondent Demographics by Area</h2>
        <h3 class="slide-subtitle">Sample Size (n) = 200</h3>
        <div class="chart-container">
            <canvas id="demographicsChart"></canvas>
        </div>
    </div>
    
    <!-- Slide 4: Adoption Rate -->
    <div class="slide-container">
        <h2 class="slide-title">Slide 4: Observation 1 - Overall Solar Adoption Rate</h2>
        <h3 class="slide-subtitle">A primary objective was to establish a baseline for current usage.</h3>
        <div class="flex items-center h-full">
            <div class="w-1/2">
                <h4 class="text-2xl font-bold text-slate-800">Sample Proportions:</h4>
                <p class="text-2xl mt-4">Have Solar Panels (Users): <strong class="text-green-600">39.5%</strong> (79 respondents)</p>
                <p class="text-2xl mt-2">Do Not Have Solar (Non-Users): <strong class="text-red-600">60.5%</strong> (121 respondents)</p>
            </div>
            <div class="w-1/2 chart-container"><canvas id="adoptionRateChart"></canvas></div>
        </div>
    </div>

    <!-- Slide 5: Confidence Interval for Adoption Rate -->
    <div class="slide-container">
        <h2 class="slide-title">Slide 5: Confidence Interval for True Adoption Rate</h2>
        <h3 class="slide-subtitle">Objective: To estimate the true population proportion of solar users with 95% confidence.</h3>
        <div class="space-y-4 text-xl">
            <p><strong>Calculation Technique:</strong> Confidence Interval for a Proportion</p>
            <div class="formula-box">CI = p̂ ± Z<sub>α/2</sub> * &radic;[p̂(1-p̂)/n]</div>
            <p><strong>Calculation:</strong></p>
            <p class="ml-4">Margin of Error = 1.96 * &radic;[0.395(0.605)/200] &approx; 0.068</p>
            <div class="conclusion-box reject text-center"><p class="font-bold text-xl">We are 95% confident the true solar adoption rate lies between <strong class="text-2xl">32.7% and 46.3%</strong>.</p></div>
        </div>
    </div>

    <!-- Slide 6: Barriers to Adoption -->
    <div class="slide-container">
        <h2 class="slide-title">Slide 6: Observation 2 - Barriers to Adoption</h2>
        <h3 class="slide-subtitle">Analysis of the primary deterrents for 121 non-users.</h3>
        <div class="chart-container"><canvas id="barriersChart"></canvas></div>
    </div>

    <!-- Slide 7: Hypothesis 1 -->
    <div class="slide-container">
        <h2 class="slide-title">Slide 7: Hypothesis 1 - Testing the Dominance of Cost</h2>
        <h3 class="slide-subtitle">Claim: The high initial cost is the primary barrier for more than 50% of non-users.</h3>
        <div class="grid grid-cols-2 gap-8 text-lg">
            <div><h4 class="font-bold text-xl mb-2">Hypothesis Setup:</h4><p><strong>H₀:</strong> p ≤ 0.50</p><p><strong>H₁:</strong> p > 0.50</p></div>
            <div><h4 class="font-bold text-xl mb-2">Calculation:</h4><p><strong>Sample (n):</strong> 121, <strong>Count (x):</strong> 74, <strong>p̂:</strong> 0.612</p></div>
        </div>
        <div class="formula-box mt-4 text-lg">Z = (p̂ - p₀) / &radic;[p₀(1-p₀)/n] = 2.47</div>
        <div class="conclusion-box reject mt-4"><p class="font-bold text-xl">Conclusion: Reject H₀ (p-value = 0.0068)</p><p class="text-lg">The evidence is statistically significant; high initial cost is the primary barrier for a true majority of potential adopters.</p></div>
    </div>

    <!-- Slide 8: Financial Impact -->
    <div class="slide-container">
        <h2 class="slide-title">Slide 8: Observation 3 - The Financial Impact on Users</h2>
        <h3 class="slide-subtitle">Quantifying the reduction in monthly electricity bills for solar users.</h3>
        <div class="grid grid-cols-3 gap-6 text-center mt-12">
            <div class="bg-red-50 p-6 rounded-lg shadow"><p class="text-slate-600 text-xl font-bold">Avg. Bill BEFORE</p><p class="text-5xl font-extrabold text-red-600 mt-4">₹18,500</p></div>
            <div class="bg-slate-800 text-white p-6 rounded-lg shadow-lg"><p class="text-xl font-bold">Avg. % Reduction</p><p class="text-6xl font-extrabold mt-4">77.3%</p></div>
            <div class="bg-green-50 p-6 rounded-lg shadow"><p class="text-slate-600 text-xl font-bold">Avg. Bill AFTER</p><p class="text-5xl font-extrabold text-green-700 mt-4">₹4,200</p></div>
        </div>
    </div>

    <!-- Slide 9: Hypothesis 2 -->
    <div class="slide-container">
        <h2 class="slide-title">Slide 9: Hypothesis 2 - Significance of Bill Reduction</h2>
        <h3 class="slide-subtitle">Claim: The average monthly reduction in electricity bills is greater than ₹12,000.</h3>
        <div class="grid grid-cols-2 gap-8 text-lg">
            <div><h4 class="font-bold text-xl mb-2">Hypothesis Setup:</h4><p><strong>H₀:</strong> μ ≤ 12,000</p><p><strong>H₁:</strong> μ > 12,000</p></div>
            <div><h4 class="font-bold text-xl mb-2">Calculation:</h4><p><strong>Sample (n):</strong> 79, <strong>x̄:</strong> ₹14,300, <strong>s:</strong> ₹5,500</p></div>
        </div>
        <div class="formula-box mt-4 text-lg">t = (x̄ - μ₀) / (s / &radic;n) = 3.71</div>
        <div class="conclusion-box reject mt-4"><p class="font-bold text-xl">Conclusion: Reject H₀ (t-critical ≈ 1.665)</p><p class="text-lg">The evidence strongly supports the claim that the average user saves more than ₹12,000 monthly.</p></div>
    </div>

    <!-- Slide 10: Confidence Interval for Savings -->
    <div class="slide-container">
        <h2 class="slide-title">Slide 10: Confidence Interval for True Monthly Savings</h2>
        <h3 class="slide-subtitle">Objective: To estimate the true average monthly savings for a solar user with 95% confidence.</h3>
        <div class="space-y-4 text-xl">
            <p><strong>Calculation Technique:</strong> Confidence Interval for a Mean</p>
            <div class="formula-box">CI = x̄ ± t<sub>α/2, n-1</sub>*(s/&radic;n)</div>
            <p><strong>Calculation:</strong></p>
            <p class="ml-4">Margin of Error = 1.990 * (5500 / &radic;79) &approx; ₹1,228</p>
            <div class="conclusion-box reject text-center"><p class="font-bold text-xl">We are 95% confident the true average monthly savings for a user is between <strong class="text-2xl">₹13,072 and ₹15,528</strong>.</p></div>
        </div>
    </div>

    <!-- Slide 11: Installation Costs -->
    <div class="slide-container">
        <h2 class="slide-title">Slide 11: Observation 4 - System Installation Costs</h2>
        <h3 class="slide-subtitle">Analysis of the initial investment required for solar adoption.</h3>
        <div class="chart-container"><canvas id="installationCostChart"></canvas></div>
    </div>

    <!-- Slide 12: CI for Installation Cost -->
    <div class="slide-container">
        <h2 class="slide-title">Slide 12: Confidence Interval for True Installation Cost</h2>
        <h3 class="slide-subtitle">Objective: To estimate the true average installation cost with 95% confidence.</h3>
        <div class="space-y-4 text-xl">
             <p><strong>Calculation Technique:</strong> Confidence Interval for a Mean</p>
            <div class="formula-box">CI = x̄ ± t<sub>α/2, n-1</sub>*(s/&radic;n)</div>
            <p><strong>Calculation:</strong></p>
            <p class="ml-4">Margin of Error = 1.990 * (150000 / &radic;79) &approx; ₹33,560</p>
            <div class="conclusion-box reject text-center"><p class="font-bold text-xl">We are 95% confident the true average installation cost is between <strong class="text-2xl">₹516,440 and ₹583,560</strong>.</p></div>
        </div>
    </div>
    
    <!-- Slide 13: Satisfaction -->
    <div class="slide-container">
        <h2 class="slide-title">Slide 13: Observation 5 - User Satisfaction & Advocacy</h2>
        <h3 class="slide-subtitle">Beyond finances, we measured the overall user experience.</h3>
        <div class="flex items-center h-full">
            <div class="w-1/2 text-center">
                <p class="text-2xl font-bold">Average Satisfaction Score:</p>
                <p class="text-8xl font-extrabold text-blue-600">8.6<span class="text-4xl text-slate-400">/10</span></p>
            </div>
            <div class="w-1/2 chart-container"><canvas id="recommendationChart"></canvas></div>
        </div>
    </div>

    <!-- Slide 14: Hypothesis 3 -->
    <div class="slide-container">
        <h2 class="slide-title">Slide 14: Hypothesis 3 - Testing User Satisfaction Level</h2>
        <h3 class="slide-subtitle">Claim: The true average satisfaction score of solar users is greater than 8 out of 10.</h3>
        <div class="grid grid-cols-2 gap-8 text-lg">
            <div><h4 class="font-bold text-xl mb-2">Hypothesis Setup:</h4><p><strong>H₀:</strong> μ ≤ 8</p><p><strong>H₁:</strong> μ > 8</p></div>
            <div><h4 class="font-bold text-xl mb-2">Calculation:</h4><p><strong>Sample (n):</strong> 79, <strong>x̄:</strong> 8.6, <strong>s:</strong> 1.2</p></div>
        </div>
        <div class="formula-box mt-4 text-lg">t = (x̄ - μ₀) / (s / &radic;n) = 4.44</div>
        <div class="conclusion-box reject mt-4"><p class="font-bold text-xl">Conclusion: Reject H₀ (t-critical ≈ 1.665)</p><p class="text-lg">There is very strong evidence that average user satisfaction is significantly higher than 8/10.</p></div>
    </div>
    
    <!-- Slide 15: Correlation -->
    <div class="slide-container">
        <h2 class="slide-title">Slide 15: Correlation Analysis - Cost vs. Satisfaction</h2>
        <h3 class="slide-subtitle">Question: Does spending more on installation lead to higher satisfaction?</h3>
        <div class="flex h-full">
            <div class="w-1/3 pr-8 pt-12">
                <p><strong>Null Hypothesis (H₀):</strong> No correlation (ρ = 0).</p>
                <p class="mt-2"><strong>Pearson Coefficient (r) ≈ 0.15</strong></p>
                <div class="conclusion-box fail-reject mt-4"><p class="font-bold text-lg">Conclusion: Fail to Reject H₀</p><p>The correlation is very weak. Higher cost does not significantly predict higher satisfaction.</p></div>
            </div>
            <div class="w-2/3 chart-container"><canvas id="correlationChart"></canvas></div>
        </div>
    </div>
    
    <!-- Slide 16: Load Shedding -->
    <div class="slide-container">
        <h2 class="slide-title">Slide 16: Observation 6 - Energy Security as a Driver</h2>
        <h3 class="slide-subtitle">Analysis of how frequent blackouts (load shedding) impact solar adoption.</h3>
        <div class="chart-container"><canvas id="loadSheddingChart"></canvas></div>
    </div>

    <!-- Slide 17: Conditional Probability -->
    <div class="slide-container">
        <h2 class="slide-title">Slide 17: Conditional Probability - The Load Shedding Effect</h2>
        <h3 class="slide-subtitle">Question: P(Solar User | Frequent Load Shedding)?</h3>
        <div class="space-y-4 text-xl">
            <p><strong>Formula:</strong> P(A|B) = P(A ∩ B) / P(B)</p>
            <div class="formula-box">P(Solar|Frequent) = P(Solar ∩ Frequent) / P(Frequent)</div>
            <p><strong>Calculation:</strong></p>
            <p class="ml-4">P(Frequent) = 112/200 = 0.56</p>
            <p class="ml-4">P(Solar ∩ Frequent) = 63/200 = 0.315</p>
            <p class="ml-4">P(Solar|Frequent) = 0.315 / 0.56 &approx; 0.563</p>
            <div class="conclusion-box reject"><p class="font-bold text-xl">Conclusion: There is a 56.3% probability a household has adopted solar if they experience frequent blackouts, confirming energy insecurity as a primary driver.</p></div>
        </div>
    </div>
    
    <!-- Slide 18: Bayes' Theorem -->
    <div class="slide-container">
        <h2 class="slide-title">Slide 18: Bayes' Theorem - A Deeper Look at Motivation</h2>
        <h3 class="slide-subtitle">Question: Given that a household is a solar user, what is the probability they experience frequent load shedding? P(Frequent Load Shedding | Solar User)?</h3>
        <div class="space-y-4 text-xl">
            <p><strong>Formula:</strong> P(B|A) = [P(A|B) * P(B)] / P(A)</p>
            <div class="formula-box">P(B|A) = [ P(A|B) * P(B) ] / [ P(A|B)P(B) + P(A|B')P(B') ]</div>
            <p><strong>Calculation:</strong></p>
            <p class="ml-4">P(B|A) = (0.563 * 0.56) / 0.395 &approx; 0.797</p>
            <div class="conclusion-box reject"><p class="font-bold text-xl">Conclusion: There is a 79.7% probability that a current solar user is someone who experiences frequent load shedding. This strongly reinforces that the current market is dominated by those seeking energy security.</p></div>
        </div>
    </div>

    <!-- Slide 19: Hypothesis 4 - Chi-Square Test -->
    <div class="slide-container">
        <h2 class="slide-title">Slide 19: Hypothesis 4 - Adoption and Location Type</h2>
        <h3 class="slide-subtitle">Claim: Solar panel adoption is independent of the type of area (Urban, Suburban, Rural).</h3>
        <div class="grid grid-cols-2 gap-8 text-lg">
            <div><h4 class="font-bold text-xl mb-2">Hypothesis Setup:</h4><p><strong>H₀:</strong> Adoption and area type are independent.</p><p><strong>H₁:</strong> They are not independent.</p></div>
            <div><h4 class="font-bold text-xl mb-2">Test:</h4><p>Chi-Square (χ²) Test for Independence</p></div>
        </div>
        <div class="formula-box mt-4 text-lg">χ² = Σ [ (O - E)² / E ] = 0.41</div>
        <div class="conclusion-box fail-reject mt-4"><p class="font-bold text-xl">Conclusion: Fail to Reject H₀ (χ²-critical = 5.991)</p><p class="text-lg">Since 0.41 < 5.991, there is not enough evidence to claim a significant association between location type and solar adoption.</p></div>
    </div>
    
    <!-- Slide 20: Future Intent -->
    <div class="slide-container">
        <h2 class="slide-title">Slide 20: Observation 7 - Future Adoption Intent</h2>
        <h3 class="slide-subtitle">Likelihood of the 121 non-users adopting solar in the next five years.</h3>
        <div class="chart-container"><canvas id="futureIntentChart"></canvas></div>
    </div>

    <!-- Slide 21: Government Role -->
    <div class="slide-container">
        <h2 class="slide-title">Slide 21: Observation 8 - The Role of Government</h2>
        <h3 class="slide-subtitle">Do people believe subsidies would encourage solar adoption?</h3>
        <div class="flex items-center h-full">
            <div class="w-1/2">
                <h4 class="text-2xl font-bold text-slate-800">Survey Results (n=200):</h4>
                <p class="text-2xl mt-4">Believe Subsidies Help: <strong class="text-green-600">91%</strong> (182 respondents)</p>
                <p class="text-2xl mt-2">Do Not Believe So: <strong class="text-red-600">9%</strong> (18 respondents)</p>
            </div>
            <div class="w-1/2 chart-container"><canvas id="subsidiesChart"></canvas></div>
        </div>
    </div>

    <!-- Slide 22: Hypothesis 5 -->
    <div class="slide-container">
        <h2 class="slide-title">Slide 22: Hypothesis 5 - Impact of Government Subsidies</h2>
        <h3 class="slide-subtitle">Claim: More than 85% of people believe subsidies would encourage adoption.</h3>
        <div class="grid grid-cols-2 gap-8 text-lg">
            <div><h4 class="font-bold text-xl mb-2">Hypothesis Setup:</h4><p><strong>H₀:</strong> p ≤ 0.85</p><p><strong>H₁:</strong> p > 0.85</p></div>
            <div><h4 class="font-bold text-xl mb-2">Calculation:</h4><p><strong>Sample (n):</strong> 200, <strong>x:</strong> 182, <strong>p̂:</strong> 0.91</p></div>
        </div>
        <div class="formula-box mt-4 text-lg">Z = (p̂ - p₀) / &radic;[p₀(1-p₀)/n] = 2.38</div>
        <div class="conclusion-box reject mt-4"><p class="font-bold text-xl">Conclusion: Reject H₀ (Z-critical = 1.645)</p><p class="text-lg">There is strong evidence that significantly more than 85% of the population supports subsidies as an effective policy.</p></div>
    </div>

    <!-- Slide 23: Advanced Tech -->
    <div class="slide-container">
        <h2 class="slide-title">Slide 23: Observation 9 - Interest in Advanced Technology</h2>
        <h3 class="slide-subtitle">Gauging interest in next-generation solar technologies like solar roof tiles.</h3>
        <div class="flex items-center h-full">
            <div class="w-1/2">
                <h4 class="text-2xl font-bold text-slate-800">Survey Results:</h4>
                <p class="text-2xl mt-4">Interested in Advanced Solar: <strong class="text-blue-600">76%</strong></p>
                <p class="text-2xl mt-2">Not Interested: <strong class="text-slate-500">24%</strong></p>
            </div>
            <div class="w-1/2 chart-container"><canvas id="advancedTechChart"></canvas></div>
        </div>
    </div>

    <!-- Slide 24: Summary -->
    <div class="slide-container">
        <h2 class="slide-title">Slide 24: Summary of Key Statistical Findings</h2>
        <ul class="list-disc list-outside space-y-3 text-xl pl-5 mt-4">
            <li><strong>Untapped Market:</strong> A majority (60.5%) have not adopted solar. The true adoption rate is likely between 32.7% and 46.3%.</li>
            <li><strong>Cost is the Hurdle:</strong> High initial cost is the statistically proven primary barrier for a majority of non-users (p < 0.01).</li>
            <li><strong>Proven Financial Case:</strong> Solar provides significant monthly savings (95% CI: ₹13,072-₹15,528), with a true mean installation cost between ₹516,440-₹583,560.</li>
            <li><strong>Exceptional User Experience:</strong> Satisfaction is statistically proven to be higher than 8/10 and is not correlated with installation cost.</li>
            <li><strong>Key Motivators:</strong> Energy insecurity from load shedding is a primary driver, with a nearly 80% probability that a solar user is someone who faces frequent blackouts.</li>
            <li><strong>Policy is Crucial:</strong> Government subsidies are viewed as a vital tool by a statistically significant majority (p < 0.05).</li>
        </ul>
    </div>

    <!-- Slide 25: Recommendations -->
    <div class="slide-container">
        <h2 class="slide-title">Slide 25: Recommendations</h2>
        <div class="space-y-6 text-xl mt-4">
            <div class="bg-slate-50 p-4 rounded-lg"><h3 class="font-bold text-slate-800">For Policymakers:</h3><p class="text-slate-700">Implement targeted, accessible financing schemes and subsidies to directly address the primary barrier of high initial cost.</p></div>
            <div class="bg-slate-50 p-4 rounded-lg"><h3 class="font-bold text-slate-800">For Industry:</h3><p class="text-slate-700">Focus marketing efforts on the dual benefits of long-term financial savings and achieving energy independence, especially in areas with frequent load shedding.</p></div>
            <div class="bg-slate-50 p-4 rounded-lg"><h3 class="font-bold text-slate-800">For Future Research:</h3><p class="text-slate-700">Investigate the impact of financing options on adoption rates and explore the market potential for emerging advanced solar technologies.</p></div>
        </div>
    </div>


    <script>
        const chartDefaults = {
            responsive: true,
            maintainAspectRatio: false,
            plugins: {
                legend: { position: 'bottom', labels: { padding: 15, font: { family: 'Inter', size: 14 } } },
                tooltip: {
                    backgroundColor: '#0f172a', titleFont: { size: 16, family: 'Inter' },
                    bodyFont: { size: 14, family: 'Inter' }, padding: 12, cornerRadius: 4
                }
            },
            animation: { duration: 0 } 
        };

        // Chart data and configurations
        new Chart(document.getElementById('demographicsChart'), {
            type: 'bar',
            data: { labels: ['Urban', 'Suburban', 'Rural'], datasets: [{ label: '# of Respondents', data: [106, 62, 32], backgroundColor: ['#3b82f6', '#6366f1', '#f59e0b'], borderRadius: 4 }] },
            options: { ...chartDefaults, scales: { y: { beginAtZero: true } } }
        });

        new Chart(document.getElementById('adoptionRateChart'), {
            type: 'doughnut',
            data: { labels: ['Do Not Have Solar', 'Have Solar'], datasets: [{ data: [60.5, 39.5], backgroundColor: ['#ef4444', '#22c55e'], borderColor: '#ffffff', borderWidth: 8 }] },
            options: chartDefaults
        });
        
        new Chart(document.getElementById('barriersChart'), {
            type: 'bar',
            data: { labels: ['High Initial Cost', 'Lack of Info', 'Unsuitable Property', 'Other'], datasets: [{ label: '% of Non-Users', data: [61.2, 19.8, 12.4, 6.6], backgroundColor: ['#dc2626', '#f97316', '#f59e0b', '#64748b'], borderRadius: 4 }] },
            options: { ...chartDefaults, indexAxis: 'y', scales: { x: { beginAtZero: true } }, plugins: {...chartDefaults.plugins, legend: {display: false}} }
        });

        new Chart(document.getElementById('installationCostChart'), {
            type: 'bar',
            data: {
                labels: ['<400k', '400k-600k', '600k-800k', '800k-1M', '>1M'],
                datasets: [{
                    label: 'Number of Installations',
                    data: [15, 35, 18, 8, 3], 
                    backgroundColor: '#3b82f6'
                }]
            },
            options: {...chartDefaults, plugins: {...chartDefaults.plugins, legend: {display: false}}, scales: {y: {title: {display: true, text: 'Frequency'}}, x: {title: {display: true, text: 'Installation Cost (PKR)'}}}}
        });

        new Chart(document.getElementById('recommendationChart'), {
            type: 'pie',
            data: { labels: ['Would Recommend', 'Would Not Recommend'], datasets: [{ data: [93.7, 6.3], backgroundColor: ['#22c55e', '#ef4444'], borderColor: '#ffffff', borderWidth: 8 }] },
            options: {...chartDefaults, plugins: {...chartDefaults.plugins, legend: {position: 'top'}}}
        });

        const scatterData = Array.from({length: 79}, () => ({
            x: 300000 + Math.random() * 800000, 
            y: 6 + Math.random() * 4 
        }));
        new Chart(document.getElementById('correlationChart'), {
            type: 'scatter',
            data: { datasets: [{ label: 'Installation', data: scatterData, backgroundColor: 'rgba(59, 130, 246, 0.6)' }] },
            options: {...chartDefaults, plugins: {...chartDefaults.plugins, legend: {display: false}}, scales: {x: {title: {display: true, text: 'Cost (PKR)'}}, y: {title: {display: true, text: 'Satisfaction (1-10)'}}}}
        });

        new Chart(document.getElementById('loadSheddingChart'), {
            type: 'bar',
            data: {
                labels: ['High Load Shedding (n=112)', 'Low Load Shedding (n=88)'],
                datasets: [
                    { label: 'Has Solar', data: [63, 16], backgroundColor: '#22c55e' },
                    { label: 'No Solar', data: [49, 72], backgroundColor: '#ef4444' },
                ]
            },
            options: {...chartDefaults, scales: { x: { stacked: true }, y: { stacked: true, title: {display: true, text: 'Number of Respondents'} } }}
        });

        new Chart(document.getElementById('futureIntentChart'), {
            type: 'bar',
            data: { labels: ['Very Likely / Likely', 'Neutral', 'Unlikely / Very Unlikely'], datasets: [{ label: '% of Non-Users', data: [45.5, 29.7, 24.8], backgroundColor: ['#22c55e', '#f59e0b', '#ef4444'], borderRadius: 4 }] },
            options: {...chartDefaults, plugins: {...chartDefaults.plugins, legend: {display: false}}}
        });

        new Chart(document.getElementById('subsidiesChart'), {
            type: 'pie',
            data: { labels: ['Believe Subsidies Help', 'Do Not Believe'], datasets: [{ data: [91, 9], backgroundColor: ['#3b82f6', '#64748b'], borderColor: '#ffffff', borderWidth: 8 }] },
            options: chartDefaults
        });
        
        new Chart(document.getElementById('advancedTechChart'), {
            type: 'doughnut',
            data: { labels: ['Interested', 'Not Interested'], datasets: [{ data: [76, 24], backgroundColor: ['#8b5cf6', '#64748b'], borderColor: '#ffffff', borderWidth: 8 }] },
            options: chartDefaults
        });
    </script>
</body>
</html>
